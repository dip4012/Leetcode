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
    map<int, int> inorderIndexMap;
    int preorderIndex;

    TreeNode *constructTree(vector<int> preorder, int left, int right)
    {
        if (left > right)
            return nullptr;

        int rootValue = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootValue);
        root->left = constructTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root->right = constructTree(preorder, inorderIndexMap[rootValue] + 1, right);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        preorderIndex = 0;

        for (int i = 0; i < inorder.size(); i++)
            inorderIndexMap[inorder[i]] = i;

        return constructTree(preorder, 0, inorder.size() - 1);
    }
};