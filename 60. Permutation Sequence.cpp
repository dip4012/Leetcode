#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &num, string &ans, vector<int> fact, int n, int k)
    {
        if (n == 1)
        {
            ans.append(to_string(num.back()));
            return;
        }

        int index = k / fact[n - 1];
        if (k % fact[n - 1] == 0)
            index--;

        ans.append(to_string(num[index]));
        num.erase(num.begin() + index);
        k -= fact[n - 1] * index;

        solve(num, ans, fact, n - 1, k);
    }

public:
    string getPermutation(int n, int k)
    {
        if (n == 1)
            return "1";

        string ans = "";
        vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<int> num;
        for (int i = 1; i <= n; i++)
            num.push_back(i);
        solve(num, ans, fact, n, k);
        return ans;
    }
};