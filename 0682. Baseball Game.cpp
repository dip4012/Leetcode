#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> stk;
        for (string op : ops)
        {
            if (op == "+")
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.push(a);
                stk.push(a + b);
            }
            else if (op == "D")
            {
                stk.push(2 * stk.top());
            }
            else if (op == "C")
            {
                stk.pop();
            }
            else
            {
                stk.push(stoi(op));
            }
        }

        int ans = 0;
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};