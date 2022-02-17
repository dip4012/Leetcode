#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";
        int sum, carry = 0;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            sum = a[i] - '0' + b[j] - '0' + carry;
            carry = sum / 2;
            ans.append(to_string(sum % 2));
            i++;
            j++;
        }

        while (i < a.size())
        {
            sum = a[i] - '0' + carry;
            carry = sum / 2;
            ans.append(to_string(sum % 2));
            i++;
        }

        while (j < b.size())
        {
            sum = b[j] - '0' + carry;
            carry = sum / 2;
            ans.append(to_string(sum % 2));
            j++;
        }

        if (carry)
            ans.append(to_string(carry));

        reverse(ans.begin(), ans.end());
        return ans;
    }
};