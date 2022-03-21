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
        Node *itr = head;

        while (itr != nullptr)
        {
            Node *temp = itr->next;
            itr->next = new Node(itr->val);
            itr->next->next = temp;
            itr = temp;
        }

        itr = head;
        while (itr != nullptr)
        {
            if (itr->random != nullptr)
                itr->next->random = itr->random->next;
            itr = itr->next->next;
        }

        Node *dummyNode = new Node(0);
        Node *crawl = dummyNode;
        itr = head;
        while (itr != nullptr)
        {
            crawl->next = itr->next;
            crawl = crawl->next;
            itr->next = itr->next->next;
            itr = itr->next;
        }

        return dummyNode->next;
    }
};