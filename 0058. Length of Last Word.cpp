#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int wordLength = s[0] == ' ' ? 0 : 1;
        for (int ch = 1; ch < s.length(); ch++)
        {
            if (s[ch] != ' ')
            {
                if (s[ch - 1] == ' ')
                    wordLength = 0;
                wordLength++;
            }
        }
        return wordLength;
    }
};