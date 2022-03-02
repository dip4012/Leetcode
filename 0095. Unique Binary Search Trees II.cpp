#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    vector<TreeNode *> solve(int start, int end)
    {
        vector<TreeNode *> ans;

        if (start > end)
        {
            ans.push_back(nullptr);
            return ans;
        }

        if (start == end)
        {
            ans.push_back(new TreeNode(start));
            return ans;
        }

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> l = solve(start, i - 1);
            vector<TreeNode *> r = solve(i + 1, end);

            for (auto lnode : l)
            {
                for (auto rnode : r)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }
};