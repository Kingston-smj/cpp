#include <iostream>
using namespace std;

int main(){
    int arr[] = {34, 232, 23, 23345,28};

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        if (arr[i] ! = 28){
            cout<< " number exists ";
        }
        else{
            cout<< " number not found ";
        }
    }

    return 0;
}