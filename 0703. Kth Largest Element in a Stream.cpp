#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int t, vector<int> &nums)
    {
        k = t;
        for (int n : nums)
            add(n);
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
