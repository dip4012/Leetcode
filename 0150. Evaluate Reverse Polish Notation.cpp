#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (string s : tokens)
        {
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                if (s == "+")
                    stk.push(a + b);
                if (s == "-")
                    stk.push(b - a);
                if (s == "*")
                    stk.push(a * b);
                if (s == "/")
                    stk.push(b / a);
            }
            else
            {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};