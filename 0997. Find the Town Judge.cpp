#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> arr(n, 0);
        for (vector<int> t : trust)
        {
            arr[t[1] - 1]++;
            arr[t[0] - 1]--;
        }

        for (int i = 0; i < n; i++)
            if (arr[i] == n - 1)
                return i + 1;
        return -1;
    }
};