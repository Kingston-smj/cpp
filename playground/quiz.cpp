#include <iostream>

using namespace std;

int main(){
    string questions[] = {"whweyiwf", "vwcbhwc?" , "scbshcs"};
    string answer [] = {"hscs", "scbhsc", "scbshc"};
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