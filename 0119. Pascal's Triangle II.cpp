#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> r(rowIndex + 1, 0);
        r[0] = 1;
        for (int i = 1; i <= rowIndex; i++)
            for (int j = i; j >= 1; j--)
                r[j] += r[j - 1];
        return r;
    }
};