#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        s += " ";
        int len = s.length();
        string rev_s = "";
        int pos = 0;
        while (s[pos] == ' ')
            pos++;

        string word = "";
        while (pos < len)
        {
            char ch = s[pos];
            if (ch == ' ')
            {
                rev_s = word + " " + rev_s;
                word = "";
                while (s[pos] == ' ' && pos < len)
                    pos++;
                continue;
            }
            else
            {
                word += ch;
            }
            pos++;
        }

        rev_s.pop_back();
        return rev_s;
    }
};