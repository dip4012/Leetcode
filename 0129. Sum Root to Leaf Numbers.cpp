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
    int ans = 0;

    void dfs(TreeNode *node, int cur)
    {
        if (node == nullptr)
            return;

        cur = cur * 10 + node->val;
        if (!node->left && !node->right)
        {
            ans += cur;
            return;
        }
        else
        {
            dfs(node->left, cur);
            dfs(node->right, cur);
        }
    }

public:
    int sumNumbers(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};