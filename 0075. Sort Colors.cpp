#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count0s = 0, count1s = 0, count2s = 0;
        for (int i : nums)
        {
            if (i == 0)
                count0s++;
            else if (i == 1)
                count1s++;
            else
                count2s++;
        }

        int i = 0;

        while (count0s)
        {
            nums[i] = 0;
            count0s--;
            i++;
        }

        while (count1s)
        {
            nums[i] = 1;
            count1s--;
            i++;
        }

        while (count2s)
        {
            nums[i] = 2;
            count2s--;
            i++;
        }
    }
};