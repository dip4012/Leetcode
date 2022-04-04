#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int count = 0;
        vector<int> arr(60, 0);
        for (int t : time)
        {
            int k = t % 60;
            if (k == 0)
                count += arr[k];
            else
                count += arr[60 - k];
            arr[k]++;
        }
        return count;
    }
};