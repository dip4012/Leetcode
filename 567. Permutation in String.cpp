#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        vector<int> s1map(26, 0), s2map(26, 0);
        for (int i = 0; i < s1.length(); i++)
        {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (s1map[i] == s2map[i])
                count++;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++)
        {
            int r = s2[i + s1.length()] - 'a';
            int l = s2[i] - 'a';

            if (count == 26)
                return true;

            s2map[r]++;
            if (s2map[r] == s1map[r])
                count++;
            else if (s2map[r] == s1map[r] + 1)
                count--;

            s2map[l]--;
            if (s2map[l] == s1map[l])
                count++;
            else if (s2map[l] == s1map[l] - 1)
                count--;
        }
        return count == 26;
    }
};