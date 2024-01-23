#include <iostream>

using namespace std;

int max(int x, int y){
    return x>y?x:y;
}

int min(int x, int y){
    return x<y?x:y;
}

int main (){
    int x, y;
    int (*fp)(int,int);
    fp = max;
    x = (*fp)(10,5);

    fp = min;
    y = (*fp)(10,5);


    cout << x << " " << y;

    return 0;
}