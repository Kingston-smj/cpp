#include <iostream>
using namespace std;

int main()
{
    int number = 0;
    int sum = 0;
    int count = 0;
    int limit;
    cout<<"How many numbers do you want to add? ";
    cin >> limit;
    do {
        
        cout<<"enter a number: ";
        cin >> number;
        count+=1;
        sum += number;

    } while(count < limit);
    cout<<"Sum = " << sum <<'\n';



    return 0;
}