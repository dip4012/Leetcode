#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> addString(vector<int> num1, vector<int> num2)
    {
        vector<int> ans;
        int carry = 0;

        for (int i = 0; i < num1.size() || i < num2.size() || carry; i++)
        {
            int digit1 = i < num1.size() ? num1[i] : 0;
            int digit2 = i < num2.size() ? num2[i] : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            ans.push_back(sum % 10);
        }

        return ans;
    }

    vector<int> multiplyOneDigit(string num1, char digit, int numOfZeroes)
    {
        vector<int> ans(numOfZeroes, 0);
        int carry = 0;

        for (char x : num1)
        {
            int product = (x - '0') * (digit - '0') + carry;
            carry = product / 10;
            ans.push_back(product % 10);
        }

        if (carry)
            ans.push_back(carry);

        return ans;
    }

public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        vector<int> ans(num1.length() + num2.length(), 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < num2.length(); i++)
        {
            ans = addString(multiplyOneDigit(num1, num2[i], i), ans);
        }

        if (ans.back() == 0)
            ans.pop_back();

        string res = "";
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            res.push_back(ans[i] + '0');
        }

        return res;
    }
};