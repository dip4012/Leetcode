#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i : nums)
        {
            m[i]++;
        }

        int count = 0;
        for (auto i : m)
        {
            if (k == 0)
            {
                count += i.second > 1;
            }
            else
            {
                int j = k + i.first;
                count += m.find(j) != m.end();
            }
        }

        return count;
    }
};