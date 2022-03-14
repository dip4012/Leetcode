#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *head = root;
        Node *tail = nullptr;
        Node *cur = root;

        while (cur)
        {
            while (cur)
            {
                if (cur->left)
                {
                    if (tail)
                        tail->next = cur->left;
                    else
                        head = cur->left;

                    tail = cur->left;
                }

                if (cur->right)
                {
                    if (tail)
                        tail->next = cur->right;
                    else
                        head = cur->right;

                    tail = cur->right;
                }
                cur = cur->next;
            }

            cur = head;
            tail = nullptr;
            head = nullptr;
        }

        return root;
    }
};