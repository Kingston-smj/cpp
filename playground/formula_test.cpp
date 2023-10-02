#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float v,u,a,s;
    a = 9.81;
    cout<< "what is the final velocity (v)? ";
    cin>> v;
    cout<< "what is the distance traveled (s)? ";
    cin>> s;
    u =   sqrt((2*s) - pow(v,2));
    cout<< "the initial velocity is "<< u;


    return 0;
}