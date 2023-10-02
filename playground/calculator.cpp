#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    char op;
    double num1,num2;
    cout<<"What operator do you want to use (+ - * /)?"<<'\n';
    cin>> op;
    cout<<"What is the first number? ";
    cin>>num1;
    cout<<"What is the second number? ";
    cin>>num2;
    switch (op)
    {
    case '+'/* constant-expression */:
        /* code */
        cout<<num1<<" + "<<num2<<" = "<<num1+num2<<'\n';
        break;
    case '-'/* constant-expression */:
        /* code */
        cout<<num1<<" - "<<num2<<" = "<<num1-num2<<'\n';
        break;
    case '*'/* constant-expression */:
        /* code */
        cout<<num1<<" * "<<num2<<" = "<<num1*num2<<'\n';
        break;
    case '/'/* constant-expression */:
        /* code */
        cout<<num1<<" / "<<num2<<" = "<<num1/num2<<'\n';
        break;
    default:
        cout<<"enter a valid operator"<<'\n';
        break;
    }

    return 0;
}