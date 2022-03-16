#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int left = 0, right = s.length() - 1; left < right; left++, right--)
        {
            while (!iswalnum(s[left]) && left < right)
                left++;
            while (!iswalnum(s[right]) && left < right)
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;
        }
        return true;
    }
};