#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getStrength(vector<int> row)
    {
        auto first0 = lower_bound(row.begin(), row.end(), 0, greater<int>());
        return first0 - row.begin();
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        set<pair<int, int>> s;
        for (int i = 0; i < mat.size(); i++)
        {
            s.emplace(getStrength(mat[i]), i);
            if (s.size() > k)
                s.erase(--s.end());
        }

        vector<int> res;
        for (auto n : s)
            res.push_back(n.second);

        return res;
    }
};