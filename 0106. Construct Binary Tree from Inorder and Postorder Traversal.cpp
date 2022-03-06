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
    int postorderIndex;
    map<int, int> inorderIndexMap;

    TreeNode *constructTree(vector<int> postorder, int left, int right)
    {
        if (left > right)
            return nullptr;

        int rootValue = postorder[postorderIndex--];
        TreeNode *root = new TreeNode(rootValue);
        root->right = constructTree(postorder, inorderIndexMap[rootValue] + 1, right);
        root->left = constructTree(postorder, left, inorderIndexMap[rootValue] - 1);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        postorderIndex = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++)
            inorderIndexMap[inorder[i]] = i;

        return constructTree(postorder, 0, inorder.size() - 1);
    }
};