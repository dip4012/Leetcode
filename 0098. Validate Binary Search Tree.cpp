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
    bool solve(TreeNode *root, long long int min, long long int max)
    {
        if (!root)
            return true;

        if (root->val >= min && root->val <= max)
        {
            return solve(root->left, min, root->val - 1ll) && solve(root->right, root->val + 1ll, max);
        }

        return false;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return solve(root, INT_MIN, INT_MAX);
    }
};