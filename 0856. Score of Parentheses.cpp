#include <bits/stdc++.h>
using namespace std;

// Divide and Conquer Approach

// class Solution
// {
//     int solve(string s, int i, int j)
//     {
//         int bal = 0, ans = 0;
//         for (int k = i; k < j; k++)
//         {
//             bal += s[k] == '(' ? 1 : -1;
//             if (bal == 0)
//             {
//                 if (k - i == 1)
//                     ans++;
//                 else
//                     ans += 2 * solve(s, i + 1, k);
//                 i = k + 1;
//             }
//         }
//         return ans;
//     }

// public:
//     int scoreOfParentheses(string s)
//     {
//         return solve(s, 0, s.length());
//     }
// };

// Stack Aproach

// class Solution
// {
// public:
//     int scoreOfParentheses(string s)
//     {
//         stack<int> stk;
//         stk.push(0);
//         for (char ch : s)
//         {
//             if (ch == '(')
//                 stk.push(0);
//             else
//             {
//                 int p = stk.top();
//                 stk.pop();
//                 int q = stk.top();
//                 stk.pop();
//                 stk.push(q + max(2 * p, 1));
//             }
//         }
//         return stk.top();
//     }
// };

// Count Cores/Depth Approach

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int ans = 0, bal = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                bal++;
            else
            {
                bal--;
                if (s[i - 1] == '(')
                    ans += 1 << bal;
            }
        }
        return ans;
    }
};