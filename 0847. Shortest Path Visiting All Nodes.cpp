#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> cache;
    int endingMask;

    int dp(int node, int mask, vector<vector<int>> &graph)
    {
        if (cache[node][mask] != 0)
            return cache[node][mask];

        if ((mask & (mask - 1)) == 0)
            return 0;

        cache[node][mask] = INT_MAX - 1;
        for (auto neighbor : graph[node])
        {
            if ((mask & (1 << neighbor)) != 0)
            {
                int alreadyVisited = dp(neighbor, mask, graph);
                int notVisited = dp(neighbor, mask ^ (1 << node), graph);
                int betterOption = min(alreadyVisited, notVisited);
                cache[node][mask] = min(cache[node][mask], 1 + betterOption);
            }
        }

        return cache[node][mask];
    }

public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        endingMask = (1 << n) - 1;
        cache = vector<vector<int>>(n + 1, vector<int>(endingMask + 1));

        int best = INT_MAX;
        for (int node = 0; node < n; node++)
            best = min(best, dp(node, endingMask, graph));

        return best;
    }
};