#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    vector<pair<int, int>> stk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        int min_ele = stk.empty() ? val : min(stk.back().second, val);
        stk.push_back({val, min_ele});
    }

    void pop()
    {
        stk.pop_back();
    }

    int top()
    {
        return stk.back().first;
    }

    int getMin()
    {
        return stk.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */