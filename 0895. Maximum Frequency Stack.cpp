#include <bits/stdc++.h>
using namespace std;

class FreqStack
{
    map<int, int> freq;
    map<int, stack<int>> group;
    int maxFreq;

public:
    FreqStack()
    {
        maxFreq = 0;
    }

    void push(int val)
    {
        freq[val]++;
        group[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }

    int pop()
    {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if (group[maxFreq].size() == 0)
            maxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */