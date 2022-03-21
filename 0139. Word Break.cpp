#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
//     bool solve(string s, int start, vector<string> wordList)
//     {
//         bool ans = false;
//         for (int end = start; end < s.length(); end++)
//         {
//             string t = s.substr(start, end - start + 1);
//             ans = ans || (find(wordList.begin(), wordList.end(), t) != wordList.end() && solve(s, end + 1, wordList));
//             if (ans)
//                 break;
//         }
//         return start == s.length() ? true : ans;
//     }

// public:
//     bool wordBreak(string s, vector<string> &wordDict)
//     {
//         return solve(s, 0, wordDict);
//     }
// };

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    string word = s.substr(j, i - j);
                    if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.length()];
    }
};