#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <set>
#include <tuple>
#include <cctype>
#include <map>

class FileReader {
private:
    std::string filename;

public:
    FileReader(const std::string& fname) : filename(fname) {}

    std::vector<std::vector<std::string>> readCSV() {
        std::vector<std::vector<std::string>> result;
        std::ifstream file(filename);
        std::string line;

        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;

            while (std::getline(ss, cell, ',')) {
                row.push_back(cell);
            }

            if (row.size() == 3) {
                result.push_back(row);
            }
        }

        return result;
    }
};

class FileWriter {
private:
    std::string filename;

    int getNextId() {
        FileReader reader(filename);
        auto rows = reader.readCSV();
        if (rows.empty()) return 1;
        return std::stoi(rows.back()[0]) + 1;
    }

public:
    FileWriter(const std::string& fname) : filename(fname) {}

    bool addQuestion(const std::string& question, const std::string& answer) {
        if (question.empty() || answer.empty()) return false;

        std::ofstream file(filename, std::ios::app);
        if (!file) return false;

        file << getNextId() << "," << question << "," << answer << "\n";
        return true;
    }

    bool addMultipleQuestions(const std::vector<std::pair<std::string, std::string>>& questionsAnswers) {
        if (std::any_of(questionsAnswers.begin(), questionsAnswers.end(),
                        [](const auto& qa) { return qa.first.empty() || qa.second.empty(); })) {
            return false;
        }

        std::ofstream file(filename, std::ios::app);
        if (!file) return false;

        int nextId = getNextId();
        for (const auto& [question, answer] : questionsAnswers) {
            file << nextId++ << "," << question << "," << answer << "\n";
        }
        return true;
    }

    bool removeQuestion(int rowId) {
        FileReader reader(filename);
        auto rows = reader.readCSV();
        rows.erase(std::remove_if(rows.begin(), rows.end(),
                                  [rowId](const auto& row) { return std::stoi(row[0]) == rowId; }),
                   rows.end());

        std::ofstream file(filename);
        if (!file) return false;

        for (const auto& row : rows) {
            file << row[0] << "," << row[1] << "," << row[2] << "\n";
        }
        return true;
    }
};

class GameFunctions {
private:
    std::mt19937 rng{std::random_device{}()};
    std::map<int, std::string> categoryMap = {
        {1, "history"}, {2, "geography"}, {3, "science"},
        {4, "movie"}, {5, "mobile"}, {6, "sport"}
    };

public:
    std::string getCategoryFile(int diceRoll) {
        if (diceRoll == 6) {
            std::uniform_int_distribution<> dis(1, 6);
            diceRoll = dis(rng);
        }
        return categoryMap[diceRoll] + ".csv";
    }

    std::tuple<std::string, std::string, std::string> pickQuestionAndAnswer(
        const std::vector<std::vector<std::string>>& questions) {
        
        if (questions.empty()) {
            return std::make_tuple("", "", "");
        }

        std::uniform_int_distribution<> dis(0, questions.size() - 1);
        const auto& question = questions[dis(rng)];
        return std::make_tuple(question[0], question[1], question[2]);
    }

    int rollDice(int min = 1, int max = 6) {
        std::uniform_int_distribution<> dis(min, max);
        return dis(rng);
    }

    bool checkAnswer(const std::string& userInput, const std::string& realAnswer) {
        auto toLower = [](std::string s) {
            std::transform(s.begin(), s.end(), s.begin(),
                           [](unsigned char c){ return std::tolower(c); });
            return s;
        };

        auto trimmed = [](std::string s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
            s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), s.end());
            return s;
        };

        return toLower(trimmed(userInput)) == toLower(trimmed(realAnswer));
    }
};

class HighScoreManager {
private:
    std::string filename;

public:
    HighScoreManager(const std::string& filename) : filename(filename) {}

    // Function to load high scores from the CSV file
    std::vector<std::pair<std::string, int>> loadScores() {
        std::vector<std::pair<std::string, int>> scores;
        std::ifstream file(filename);
        std::string line;

        if (!file.is_open()) {
            std::cerr << "High score file not found. Creating new high score file.\n";
            return scores;  // Return empty if no file exists
        }

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name;
            int score;

            if (ss >> name >> score) {
                scores.emplace_back(name, score);
            }
        }

        file.close();
        return scores;
    }

    // Function to save high scores to the CSV file
    void saveScores(const std::vector<std::pair<std::string, int>>& scores) {
        std::ofstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open high score file for writing.\n";
            return;
        }

        for (const auto& entry : scores) {
            file << entry.first << "," << entry.second << "\n";
        }

        file.close();
    }

    // Function to add a new score
    void addScore(const std::string& playerName, int score) {
        // Load existing scores
        std::vector<std::pair<std::string, int>> scores = loadScores();

        // Add the new score
        scores.emplace_back(playerName, score);

        // Sort scores in descending order
        std::sort(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        // Keep only the top 5 scores
        if (scores.size() > 5) {
            scores.resize(5);
        }

        // Save the updated scores
        saveScores(scores);
    }

    // Function to display the high scores
    void displayScores() {
        std::vector<std::pair<std::string, int>> scores = loadScores();

        if (scores.empty()) {
            std::cout << "No high scores available.\n";
            return;
        }

        std::cout << "Top 5 High Scores:\n";
        for (size_t i = 0; i < scores.size(); ++i) {
            std::cout << i + 1 << ". " << scores[i].first << " - " << scores[i].second << "\n";
        }
    }
};

class GameSetup {
private:
    std::string playerName;
    int maxLives;
    int maxQuestions;
    GameFunctions gameFunctions;
    HighScoreManager highScoreManager;


public:
    GameSetup(const std::string& name, int lives, int questions)
        : playerName(name), maxLives(lives), maxQuestions(questions) {}

    void start() {
        int lives = maxLives;
        int correctAnswers = 0;
        std::set<std::string> usedQuestions;

        std::cout << "Welcome, " << playerName << "! Let's begin the game.\n";

        while (lives > 0 && correctAnswers < maxQuestions) {
            std::string input;
            std::cout << "Type 'roll' to roll the dice: ";
            std::cin >> input;

            int diceRoll = gameFunctions.rollDice();
            std::cout << "You rolled a " << diceRoll << "!\n";

            std::string categoryFile = gameFunctions.getCategoryFile(diceRoll);
            FileReader reader(categoryFile);
            auto questions = reader.readCSV();

            auto [questionId, question, answer] = gameFunctions.pickQuestionAndAnswer(questions);
            if (question.empty()) {
                std::cout << "No more questions in this category. Rolling again...\n";
                continue;
            }

            if (usedQuestions.find(questionId) != usedQuestions.end()) {
                continue;
            }

            usedQuestions.insert(questionId);

            std::cout << "Question: " << question << "\n";
            std::cout << "Your answer: ";
            std::cin.ignore();
            std::getline(std::cin, input);

            if (gameFunctions.checkAnswer(input, answer)) {
                std::cout << "Correct!\n";
                correctAnswers++;
            } else {
                std::cout << "Sorry, that's incorrect. The correct answer was: " << answer << "\n";
                lives--;
            }

            std::cout << "Lives remaining: " << lives << "\n";
            std::cout << "Correct answers: " << correctAnswers << "\n";
        }

        if (lives == 0) {
            std::cout << "Game over! You've run out of lives.\n";
        } else {
            std::cout << "Congratulations! You've answered all the questions correctly.\n";
        }

        std::cout << "Final score: " << correctAnswers << " correct answers\n";
        highScoreManager.addScore(playerName, score);
    char viewScores;
    std::cout << "Would you like to view the high scores? (y/n): ";
    std::cin >> viewScores;
    if (viewScores == 'y' || viewScores == 'Y') {
        highScoreManager.displayScores();

    }
};

int getIntInput(const std::string& prompt, int min, int max) {
    int input;
    while (true) {
        std::cout << prompt;
        if (std::cin >> input && input >= min && input <= max) {
            return input;
        }
        std::cout << "Please enter a number between " << min << " and " << max << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    std::cout << "Welcome to the Quiz Game!\n";
    
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);

    int maxLives = getIntInput("Enter the number of lives (1-10): ", 1, 10);
    int maxQuestions = getIntInput("Enter the maximum number of questions (5-20): ", 5, 20);

    GameSetup game(playerName, maxLives, maxQuestions);
    game.start();

    return 0;
}