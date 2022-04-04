#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool check(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;
        int count = 0;
        while (left <= right)
        {
            if (s[left] != s[right])
                return check(s, left, right - 1) || check(s, left + 1, right);
            left++;
            right--;
        }
        return true;
    }
};