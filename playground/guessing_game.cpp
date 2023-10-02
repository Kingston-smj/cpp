#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int number, guess, tries, count/*number of tries attempted*/;
    string response;

    srand(time(0));
    
    
    do{ 
        number = rand()%10 +1;
        do{
            cout<< "In how many tires do you think you can guess the number(1-8)? ";
            cin>> tries;
            if(tries>8){
                cout<<"WHOA! WHOA!, That's way too many tries\n";
            }
        }while(tries > 8);
        while(tries >= 0){
            cout <<"Guess the number (between 1-10): ";
            cin >> guess;
            tries--;
            count++;
            if (guess == number){
                cout<<"You guessed correctly!!\n" << "In "<< count << (count == 1? " try" : " tries")<< '\n';
                break;
            }
            else{
                cout<<"Guess "<<(guess>number? "lower\n" : "higher\n");
                cout<<"Guess again; ";
                cout<< "You have "<< tries << (tries == 1? " try" : " tries") << " remaining\n";
            }
        
            if (tries == 0 ){
                cout<< "The number was "<< number << '\n';
                break;
            }
        }
        cout << "Do you want to play again(yes(y) or no(n))? ";
        cin>> response;
    }while (response == "yes" || response == "y");

    cout<<"Thank you for playing!\n";

    return 0;
}