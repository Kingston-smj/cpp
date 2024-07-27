#include <iostream>
#include <ctime>
#include <cctype>

using namespace std;

char computer_response (); //computer input
// char user_input (char response); // not really needed....
char winner (char player, char computer); // choose winner 
char PlayAgain (char response); // play again function
int main(){
    char response, player, computer;
    string winner;
    do{
        cout<< "Choose Rock (R), Paper (P), Scissors (S): ";
        cin>> response;
        response = toupper(response);
        if(response == 'R'  || response == 'P' || response == 'S'){
            switch(response){
                case 'R':
                    cout<< "You chose rock \n";
                    break;
                case 'P':
                    cout<< "You chose paper \n";
                    break;
                case 'S':
                    cout<< "You chose scissors \n";
                    break;
            }
        }
        else{
            cout<< "Enter a proper respose"<< '\n';
        }
        
    //  char user_input(response);

    }while (response != 'R' && response != 'S' && response != 'P');
    computer = computer_response();
    winner = char winner (char player, char computer);
    
    return 0;
}
/*char user_input (char response){
    switch(response){
        case 'r' || 'R':
            cout<< "You chose rock";
    }


    return response;
}*/
char computer_response(){
    srand  (time (0));
    int num = rand%4;
    switch(num){
        case 1: return 'R';
        case 2: return 'P';
        case 3: return 'S';}}