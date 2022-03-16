#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> stk;
        int pop_index = 0;
        for (int n : pushed)
        {
            stk.push(n);
            while (!stk.empty() && stk.top() == popped[pop_index])
            {
                stk.pop();
                pop_index++;
            }
        }
        return stk.empty();
    }
};