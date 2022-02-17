#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        for (int i = 0; i < s.length(); i++)
        {
            t[i + 1] += t[i] - s[i];
        }
        return t.back();
    }
};