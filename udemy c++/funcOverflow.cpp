#include <iostream>
using namespace std;

float add (float x, float y){
    return x+y;
}
int main(){
    int a = 3.5f, b = 8.9f, c; /*using f at the end of an int variable doesn't convert it to a float*/
    c = add(a,b);
    cout<< c <<'\n';

    return 0;
}