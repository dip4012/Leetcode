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
    vector<vector<int>> ans;

    void preorder(TreeNode *root, int level)
    {
        if (!root)
            return;

        if (level == ans.size())
            ans.push_back(vector<int>());

        ans[level].push_back(root->val);
        preorder(root->left, level + 1);
        preorder(root->right, level + 1);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        preorder(root, 0);
        return vector<vector<int>>(ans.rbegin(), ans.rend());
    }
};