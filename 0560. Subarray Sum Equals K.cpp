#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> hm;
        hm[0] = 1;
        int count = 0, sum = 0;
        for (int i : nums)
        {
            sum += i;
            count += hm[sum - k];
            hm[sum]++;
        }
        return count;
    }
};