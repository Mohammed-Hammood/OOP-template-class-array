#include "Array.h"
#include <iostream>
#define Line cout << "__________________________________________________"<<endl;
using namespace std;

//change TYPE to int/char/float
#define TYPE char
int main()
{
    Array<TYPE> a;
    a.Scan();
    Line;
    cout <<"Array: ";
    a.Print();
    Line;
    a.Sort();
    cout <<"After sorting: ";
    a.Print();
    Line;
    cout <<"After shifting 1 postion to the left";
    a.ShiftLeft(1);
    a.Print();
    Line;
    cout << "Max: "<< a[a.Max()] <<endl;
    cout <<"Min: "<<a[a.Min()] <<endl;
    Line;

return 0;
}
