#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string s = countAndSay(n - 1);
        string ans = "";
        char cur_char = s[0];
        int cur_count = 0;
        for (char ch : s)
        {
            if (ch == cur_char)
                cur_count++;
            else
            {
                ans += to_string(cur_count) + cur_char;
                cur_char = ch;
                cur_count = 1;
            }
        }
        ans += to_string(cur_count) + cur_char;
        return ans;
    }
};