#include <iostream>
using namespace std;

int main()
{
    int count = 20;
    int ct = 20;

    int *ptr = &count;
    int *ptr2 = &ct;
    int &ref = count;
    cout << "count ptr: " << ptr << endl;
    cout << "count ref : " << ref << endl;
    cout << "count ptr *: " << *ptr << endl;
    cout << "count ref &: " << &ref << endl;
    cout << "ct ptr2 : " << ptr2 << endl;
    cout << "-----------------" << endl;
    return 0;
}

// ! Even if 2 variables have same value, they will store them in a different locations.