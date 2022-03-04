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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        stack<TreeNode *> t;
        vector<vector<int>> ans;
        vector<int> cur;

        if (!root)
            return ans;

        bool flag = true;
        q.push(root);
        q.push(nullptr);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node == nullptr)
            {
                if (!t.empty())
                {
                    while (!t.empty())
                    {
                        TreeNode *temp = t.top();
                        t.pop();
                        q.push(temp);
                    }
                    q.push(nullptr);
                }
                flag = !flag;
                ans.push_back(cur);
                cur.clear();
            }
            else
            {
                cur.push_back(node->val);
                if (flag)
                {
                    if (node->left)
                        t.push(node->left);
                    if (node->right)
                        t.push(node->right);
                }
                else
                {
                    if (node->right)
                        t.push(node->right);
                    if (node->left)
                        t.push(node->left);
                }
            }
        }

        return ans;
    }
};