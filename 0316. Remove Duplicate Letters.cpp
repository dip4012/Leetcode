#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> x(26, 0);
        vector<bool> visited(26, false);

        for (char ch : s)
            x[ch - 'a']++;

        stack<char> stk;
        int index;
        for (char ch : s)
        {
            x[ch - 'a']--;
            if (visited[ch - 'a'])
                continue;

            while (!stk.empty() && ch < stk.top() && x[stk.top() - 'a'] != 0)
            {
                visited[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(ch);
            visited[ch - 'a'] = true;
        }

        string ans = "";
        while (!stk.empty())
        {
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;
    }
};