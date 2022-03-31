#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";

        string res = "";
        res.append(((numerator > 0) ^ (denominator > 0)) ? "-" : "");
        long num = abs(numerator);
        long den = abs(denominator);
        res.append(to_string(num / den));
        num %= den;

        if (num == 0)
            return res;

        res.append(".");
        map<int, int> rem;
        rem[num] = res.length();
        while (num > 0)
        {
            num *= 10;
            res.append(to_string(num / den));
            num %= den;
            if (rem.find(num) != rem.end())
            {
                res.insert(rem[num], "(");
                res.append(")");
                break;
            }
            else
                rem[num] = res.length();
        }

        return res;
    }
};