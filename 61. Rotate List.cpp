#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return nullptr;

        int len = 1;
        ListNode *newHead, *tail;

        newHead = tail = head;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;

        k = k % len;
        if (k)
        {
            for (int i = 0; i < len - k; i++)
                tail = tail->next;
        }

        newHead = tail->next;
        tail->next = nullptr;
        return newHead;
    }
};