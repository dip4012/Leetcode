#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        map<int, int> hm;
        hm[0] = -1;
        int count = 0, maxLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
                count++;
            else
                count--;

            if (hm.find(count) != hm.end())
                maxLength = max(maxLength, i - hm[count]);
            else
                hm[count] = i;
        }
        return maxLength;
    }
};