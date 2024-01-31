#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int number, guess, tries;
    string response;
    srand(time(0));

    do {
        number = rand() % 100 + 1;
        tries = 0;
        while (true) { // Game loop
            cout << "Guess a number between 1-100: ";
            cin >> guess;
            tries++;
            if (number > guess) {
                cout << "Guess higher!!\n";
            }
            else if (number < guess) {
                cout << "Guess lower!!\n";
            }
            else {
                cout << "You guessed correctly in " << tries << " tries\n";
                break; // Exit the game loop when the user guesses correctly
            }
        }
        cout << "Do you want to play again? (yes/no): ";
        cin >> response;
    } while (response == "yes" || response == "y");
    cout << "Thank you for playing!!";
    return 0;
}