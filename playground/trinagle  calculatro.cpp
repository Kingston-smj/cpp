#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c;
 
    cout<<"What is the length of a? ";
    cin>>a;
    cout<<"What is the length of b?";
    cin>>b;
    c = sqrt(pow(a,2)*pow(b,2));
    cout<<"the length of c is: "<< c<< '\n';

    return 0;
}