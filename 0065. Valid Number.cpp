#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        while (s[0] == ' ')
            s.erase(s.begin());

        int n = s.length();
        int state = 1, flag = 0;
        for (int i = 0; i < n; i++)
        {
            if ('0' <= s[i] && s[i] <= '9')
            {
                flag = 1;
                if (state <= 3)
                    state = 3;
                else if (state == 4)
                    state = 4;
                else if (state <= 7)
                    state = 7;
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (state == 1 || state == 5)
                    state++;
                else
                    return false;
            }
            else if (s[i] == '.')
            {
                if (state <= 3)
                    state = 4;
                else
                    return false;
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                if (flag && (state == 3 || state == 4))
                    state = 5;
                else
                    return false;
            }
            else
                return false;
        }

        return (state == 3 || (flag && state == 4) || state == 7);
    }
};