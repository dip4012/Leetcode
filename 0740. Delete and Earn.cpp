#include <bits/stdc++.h>
using namespace std;

class Solution
{
    map<int, int> points;
    map<int, int> cache;

    int maxPoints(int num)
    {
        if (num == 0)
            return 0;

        if (num == 1)
            return points[1];

        if (cache.find(num) != cache.end())
            return cache[num];

        int gain = points[num];
        cache[num] = max(maxPoints(num - 1), maxPoints(num - 2) + gain);
        return cache[num];
    }

public:
    int deleteAndEarn(vector<int> &nums)
    {
        int maxNum = 0;

        for (int num : nums)
        {
            points[num] += num;
            maxNum = max(maxNum, num);
        }

        return maxPoints(maxNum);
    }
};