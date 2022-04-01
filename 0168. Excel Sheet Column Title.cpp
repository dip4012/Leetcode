#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber)
        {
            char t = (char)((columnNumber % 26 ? columnNumber % 26 - 1 : 25) + 'A');
            ans = t + ans;
            columnNumber = (columnNumber % 26 ? columnNumber / 26 : columnNumber / 26 - 1);
        }
        return ans;
    }
};