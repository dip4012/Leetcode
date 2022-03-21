#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        vector<int> coountTop(7, 0), countBottom(7, 0), same(7, 0);

        for (int i = 0; i < tops.size(); i++)
        {
            coountTop[tops[i]]++;
            countBottom[bottoms[i]]++;
            same[tops[i]] += tops[i] == bottoms[i] ? 1 : 0;
        }

        for (int i = 1; i < 7; i++)
        {
            if (coountTop[i] + countBottom[i] - same[i] == tops.size())
                return min(tops.size() - coountTop[i], tops.size() - countBottom[i]);
        }

        return -1;
    }
};