#include <iostream>
#include <cmath>
using namespace std;

char computer_response (char response);
char user_input (char response);
char winner (char player, char computer);
int main(){
    char player, computer;
    do{

    }while(player);
    cout<< "Choose Rock (R), Paper (P), Scissors (S): ";
    cin>> response;
    response = (toupper) response;
    if(response == R  || response == P || response == S){
        switch(response){
            case 'R':
                cout<< "You chose rock";
            break;
            case 'P':
                cout<< "You chose paper";
            break;
            case 'S':
                cout<< "You chose scizzors";
        }

    }
    else{
        cout<< "Enter a proper respose";  
    }
    
    char user_input(response);

    char computer_response (response);



    return 0;
}
char user_input (char response){
    switch(response){
        case 'r' || 'R':
            cout<< "You chose rock";
    }


    return response;
}