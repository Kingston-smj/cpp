#include <iostream>
using namespace std; 

char get_user_choice();
char get_computer_choice();
void show_choice(char choice);
void choose_winner(char player, char computer);

int main(){
    char player;
    char computer;

    player = get_user_choice();
    cout<< "your choice: ";
    show_choice(player); 
    cout << '\n';

    computer = get_computer_choice();
    cout<< "Computers choice: ";
    show_choice(computer);
    cout << '\n';

    choose_winner(player, computer);
    return 0;
}
char get_user_choice(){ 
    char player;
    cout<< "Rock Paper Scissors Game\n";
    do{
        cout<< "'R' for rock \n'P' for paper \n'S' for scissors\n";
        cin>> player;
        player = toupper(player);

    }while(player != 'R' && player != 'P' && player != 'S');
    
    return player;
}
char get_computer_choice(){
     srand (time(0));
     int num = rand()%3 + 1;

     if (num == 1){
        return 'R';
     }
     else if (num == 2){
        return 'P';
     }
     else {
        return 'S';
     }
     /*switch(num){
        case 1: return 'R';
        case 2: return 'P';
        case 3: return 'S';
     }*/
}
void show_choice(char choice){

    switch(choice){ // remove switch case and use if else
        case 'R':
        cout<< "Rock \n";
        break;
        case 'P':
        cout<< "Paper \n";
        break;
        case 'S':
        cout<< "scissors \n";
        break;
    }


}
void choose_winner(char player, char computer){

    switch(player){
        case 'R': 
        if(computer == 'R'){
            cout<< "It's a tie \n";
        }
        else if(computer == 'P'){
            cout<< "You lose \n";
        }
        else{
            cout<< "You win! \n";
        }
        break;
        case 'P': 
        if(computer == 'R'){
            cout<< "You win! \n";
        }
        else if(computer == 'P'){
            cout<< "It's a tie \n";
        }
        else{
            cout<< "You lose \n";
        }
        break;
        case 'S':
        if(computer == 'R'){
            cout<< "You lose \n";
        }
        else if(computer == 'P'){
            cout<< "You win! \n";
        }
        else{
            cout<< "It's a tie";
        }
        break;
    }

}
