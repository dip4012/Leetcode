#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> split(string s, char delim)
    {
        vector<string> res;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
        {
            res.push_back(item);
        }
        return res;
    }

public:
    int compareVersion(string version1, string version2)
    {
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');

        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size())
        {
            int n1 = stoi(v1[i]);
            int n2 = stoi(v2[j]);
            if (n1 < n2)
                return -1;
            if (n2 < n1)
                return 1;
            i++;
            j++;
        }

        while (i < v1.size())
        {
            int n1 = stoi(v1[i]);
            if (n1 > 0)
                return 1;
            i++;
        }

        while (j < v2.size())
        {
            int n2 = stoi(v2[j]);
            if (n2 > 0)
                return -1;
            j++;
        }

        return 0;
    }
};