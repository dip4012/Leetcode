#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *itr = head, *next;
        while (itr != nullptr)
        {
            next = itr->next;
            Node *copy = new Node(itr->val);
            copy->next = next;
            itr->next = copy;
            itr = next;
        }

        itr = head;
        while (itr != nullptr)
        {
            if (itr->random != nullptr)
                itr->next->random = itr->random->next;
            itr = itr->next->next;
        }

        itr = head;
        Node *copyNode = new Node(0);
        Node *copyItr = copyNode;
        while (itr != nullptr)
        {
            copyItr->next = itr->next;
            copyItr = copyItr->next;

            itr->next = itr->next->next;
            itr = itr->next;
        }

        return copyNode->next;
    }
};