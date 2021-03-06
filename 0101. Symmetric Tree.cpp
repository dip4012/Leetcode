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
    bool checkSymmetry(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return p == q;

        return (p->val == q->val) && checkSymmetry(p->left, q->right) && checkSymmetry(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return checkSymmetry(root->left, root->right);
    }
};