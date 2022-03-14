#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        map<char, char> pairs;
        pairs[')'] = '(';
        pairs[']'] = '[';
        pairs['}'] = '{';

        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                stk.push(ch);
            if (ch == ')' || ch == ']' || ch == '}')
                if (!stk.empty() && stk.top() == pairs[ch])
                    stk.pop();
                else
                    return false;
        }

        if (stk.empty())
            return true;

        return false;
    }
};