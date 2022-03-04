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
    TreeNode *firstElement = nullptr;
    TreeNode *secondElement = nullptr;
    TreeNode *prevElement = new TreeNode(INT_MIN);

    void verify(TreeNode *root)
    {
        if (firstElement == nullptr && prevElement->val > root->val)
            firstElement = prevElement;

        if (firstElement != nullptr && prevElement->val > root->val)
            secondElement = root;

        prevElement = root;
    }

    void morrisInorder(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                verify(cur);
                cur = cur->right;
                continue;
            }

            TreeNode *pred = cur->left;

            while (pred->right != nullptr && pred->right != cur)
                pred = pred->right;

            if (pred->right == nullptr)
            {
                pred->right = cur;
                cur = cur->left;
            }
            else
            {
                pred->right = nullptr;
                verify(cur);
                cur = cur->right;
            }
        }
    }

public:
    void recoverTree(TreeNode *root)
    {
        morrisInorder(root);
        swap(firstElement->val, secondElement->val);
    }
};