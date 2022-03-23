#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string ans(n, 'a');
        while (n > 0)
        {
            int last = min(26, k - (n - 1));
            ans[n - 1] += last - 1;
            k -= last;
            n--;
        }
        return ans;
    }
};