#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static int comparator(string s1, string s2)
    {
        return (s1 + s2) > (s2 + s1);
    }

public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> s;
        for (int n : nums)
            s.push_back(to_string(n));
        sort(s.begin(), s.end(), comparator);
        if (s[0] == "0")
            return "0";
        string ans = "";
        for (string str : s)
            ans += str;
        return ans;
    }
};