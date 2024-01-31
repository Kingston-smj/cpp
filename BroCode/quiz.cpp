#include <iostream>

using namespace std;

int main(){
    string questions[] = {"place holder1? ", "player holder 2?" , "place holder 3?"};
    string answer [] = {"place holder1", "place holder2", "place holder3"};
    string response[3] = {};
    int count = 0;

    for(int i=0; i< 3; i++ ){
        cout<< " "<< questions[i];
        getline (cin, response[i]);
        cout << '\n';
    }
    for (int i = 0; i < 3; i++){
        if (answer[i] == response[i]){
            count++;
        }
    }
    cout<< "You got "<< count << " correct \n";


    return 0;
}