#include <cassert>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
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

void testFileReader() {
    // Setup
    FileWriter writer("test.csv");
    writer.addQuestion("Q1", "A1");
    writer.addQuestion("Q2", "A2");

    // Test
    FileReader reader("test.csv");
    auto rows = reader.readCSV();

    // Assert
    assert(rows.size() == 2);
    assert(rows[0].size() == 3);  // Ensure each row has 3 elements
    assert(rows[0][1] == "Q1");
    assert(rows[0][2] == "A1");
    assert(rows[1][1] == "Q2");
    assert(rows[1][2] == "A2");

    std::cout << "FileReader tests passed.\n";
}

void testFileWriter() {
    // Test addQuestion
    FileWriter writer("test.csv");
    assert(writer.addQuestion("Q3", "A3"));
    
    FileReader reader("test.csv");
    auto rows = reader.readCSV();
    assert(rows.back().size() == 3);  // Ensure the new row has 3 elements
    assert(rows.back()[1] == "Q3");
    assert(rows.back()[2] == "A3");

    // Test addMultipleQuestions
    std::vector<std::pair<std::string, std::string>> questions = {
        {"Q4", "A4"}, {"Q5", "A5"}
    };
    assert(writer.addMultipleQuestions(questions));

    rows = reader.readCSV();
    assert(rows.size() == 5);  // 3 previous + 2 new
    assert(rows.back().size() == 3);  // Ensure each new row has 3 elements
    assert(rows.back()[1] == "Q5");

    // Test removeQuestion
    assert(writer.removeQuestion(1));  // Remove the first question
    rows = reader.readCSV();
    assert(rows.size() == 4);
    assert(rows[0].size() == 3);  // Ensure remaining rows still have 3 elements
    assert(rows[0][1] == "Q2");  // The second question should now be first

    std::cout << "FileWriter tests passed.\n";
}

int main() {
    testFileReader();
    testFileWriter();
    std::remove("test.csv");  // Clean up the test file
    return 0;
}