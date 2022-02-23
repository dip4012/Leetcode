#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isSame(vector<int> &nums, int start, int element)
    {
        return nums[start] == element;
    }

    bool existInFirst(vector<int> nums, int start, int element)
    {
        return nums[start] <= element;
    }

public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return false;

        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (nums[mid] == target)
                return true;

            if (isSame(nums, start, nums[mid]))
            {
                start++;
                continue;
            }

            bool pivot = existInFirst(nums, start, nums[mid]);
            bool search = existInFirst(nums, start, target);
            if (pivot ^ search)
            {
                if (pivot)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if (nums[mid] < target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};