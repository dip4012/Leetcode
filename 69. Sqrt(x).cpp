#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int ans;
        if (x == 0)
            return 0;

        int left = 1, right = x;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid > x / mid)
            {
                right = mid - 1;
            }
            else
            {
                ans = mid;
                left = mid + 1;
            }
        }

        return ans;
    }
};