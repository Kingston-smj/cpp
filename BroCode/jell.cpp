#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    string playerName, category;
    int lives, questions;
    
   // string filename = "questions.csv";

    cout << "Enter player name: ";
    getline(cin, playerName);


    cout << "Select category \n";
    cout << "G - Geography, H - history, M - movie, S - science \n";
    cin >> category;
    category = toupper(category);
    if (category == 'G'){
        co
    }


    cout << "Enter number of lives: ";//remove this 
    cin >> lives;

    cout << "Enter maximum number of questions: ";//remove this 
    cin >> questions;

  //  GameSetup game(playerName, lives, questions);
    //game.start();

    return 0;
}