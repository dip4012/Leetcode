#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto a, auto b)
             {
            if(a.front()==b.front()) return a.back()>b.back();
            else return a.front()<b.front(); });
        int ans = 1;
        int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][1] > last)
            {
                ans++;
                last = intervals[i][1];
            }
        }
        return ans;
    }
};