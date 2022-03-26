#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lb = 0, ub = nums.size() - 1;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (target < nums[mid])
                ub = mid - 1;
            else if (target > nums[mid])
                lb = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};