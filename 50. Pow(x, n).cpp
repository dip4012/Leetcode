#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == INT_MIN)
        {
            x *= x;
            n /= 2;
        }

        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }

        if (n == 0)
            return 1;

        double temp = myPow(x, n / 2);
        if (n % 2 == 0)
            return temp * temp;
        else
            return x * temp * temp;
    }
};