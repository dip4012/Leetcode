#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        map<char, int> last;
        for (int i = 0; i < s.length(); i++)
            last[s[i] - 'a'] = i;

        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
            {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};