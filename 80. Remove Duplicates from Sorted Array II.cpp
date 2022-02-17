#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 1, cur = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[k - 1])
            {
                cur++;
                if (cur <= 2)
                {
                    swap(nums[k], nums[i]);
                    k++;
                }
            }
            else
            {
                cur = 1;
                swap(nums[k], nums[i]);
                k++;
            }
        }
        return k;
    }
};