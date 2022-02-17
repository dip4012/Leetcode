#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSum(int num)
    {
        vector<int> digits;
        while (num > 0)
        {
            digits.push_back(num % 10);
            num = num / 10;
        }

        sort(digits.begin(), digits.end(), greater<int>());
        int ans = digits[0] + digits[1] + (digits[2] + digits[3]) * 10;
        return ans;
    }
};