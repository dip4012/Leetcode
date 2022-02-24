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
    ListNode *nextSubList = new ListNode();
    ListNode *tail = new ListNode();

    int getCount(ListNode *head)
    {
        int c = 0;
        ListNode *ptr = head;
        while (ptr)
        {
            c++;
            ptr = ptr->next;
        }
        return c;
    }

    void merge(ListNode *l1, ListNode *l2)
    {
        ListNode temp(0);
        ListNode *newTail = &temp;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                newTail->next = l1;
                l1 = l1->next;
                newTail = newTail->next;
            }
            else
            {
                newTail->next = l2;
                l2 = l2->next;
                newTail = newTail->next;
            }
        }

        newTail->next = l1 ? l1 : l2;

        while (newTail->next)
        {
            newTail = newTail->next;
        }

        tail->next = temp.next;

        tail = newTail;
    }

    ListNode *split(ListNode *start, int size)
    {
        ListNode *midPrev = start;
        ListNode *end = start->next;

        for (int i = 1; i < size && (midPrev->next || end->next); i++)
        {
            if (midPrev->next)
                midPrev = midPrev->next;
            if (end->next)
                end = end->next->next ? end->next->next : end->next;
        }

        ListNode *mid = midPrev->next;
        nextSubList = end->next;
        end->next = nullptr;
        midPrev->next = nullptr;
        return mid;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        int n = getCount(head);
        ListNode *start = head;
        ListNode dummy(0);
        for (int size = 1; size < n; size *= 2)
        {
            tail = &dummy;
            while (start)
            {
                if (!start->next)
                {
                    tail->next = start;
                    break;
                }
                ListNode *mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummy.next;
        }
        return dummy.next;
    }
};