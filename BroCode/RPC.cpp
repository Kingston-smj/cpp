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

    computer = get_computer_choice();
    cout<< "Computers choice: ";
    show_choice(computer);

    choose_winner(player, computer);
    return 0;
}
char get_user_choice(){ 
    char player;
    cout<< "Rock Paper Scissors Game\n";
    do{
        cout<< "'r' for rock \n'p' for paper \n's' for scissors\n";
        cin>> player;

    }while(player != 'r' && player != 'p' && player != 's');
    
    return player;
}
char get_computer_choice(){
     srand (time(0));
     int num = rand()%3 + 1;

     switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
     }
}
void show_choice(char choice){

    switch(choice){
        case 'r':
        cout<< "Rock \n";
        break;
        case 'p':
        cout<< "Paper \n";
        break;
        case 's':
        cout<< 'scissors \n';
        break;
    }


}
void choose_winner(char player, char computer){

    switch(player){
        case 'r': 
        if(computer == 'r'){
            cout<< "It's a tie \n";
        }
        else if(computer == 'p'){
            cout<< "You lose \n";
        }
        else{
            cout<< "You win! \n";
        }
        break;
        case 'p': 
        if(computer == 'r'){
            cout<< "You win! \n";
        }
        else if(computer == 'p'){
            cout<< "It's a tie \n";
        }
        else{
            cout<< "You lose \n";
        }
        break;
        case 's':
        if(computer == 'r'){
            cout<< "You lose \n";
        }
        else if(computer == 'p'){
            cout<< "You win! \n";
        }
        else{
            cout<< "It's a tie";
        }
        break;
    }

}
