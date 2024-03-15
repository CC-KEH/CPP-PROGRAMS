//* Pow(x,n)

#include <bits/stdc++.h>
using namespace std;

double my_pow(double x, int n)
{
    if (n == 0)
        return 1;
    double num = my_pow(x, n / 2);
    if (n % 2 == 1)
    {
        return num * num * x;
    }
    else if (n % 2 == 0)
    {
        return num * num;
    }
    else
        return 1 / my_pow(x, -n);
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    double x = 2.0000;
    int n = 10;
    return 0;
}
