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
    void dfs(TreeNode *root, int targetSum, vector<int> cur, vector<vector<int>> &ans)
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr && root->val == targetSum)
        {
            cur.push_back(root->val);
            ans.push_back(cur);
            return;
        }

        cur.push_back(root->val);
        dfs(root->left, targetSum - root->val, cur, ans);
        dfs(root->right, targetSum - root->val, cur, ans);
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        dfs(root, targetSum, vector<int>(), ans);
        return ans;
    }
};