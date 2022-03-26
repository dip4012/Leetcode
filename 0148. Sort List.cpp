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
    ListNode *getMid(ListNode *head)
    {
        ListNode *midPrev = nullptr;
        while (head && head->next)
        {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode *mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }

    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode *dummyNode = new ListNode();
        ListNode *crawl = dummyNode;
        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                crawl->next = list2;
                list2 = list2->next;
            }
            else
            {
                crawl->next = list1;
                list1 = list1->next;
            }
            crawl = crawl->next;
        }

        if (list1)
            crawl->next = list1;
        else
            crawl->next = list2;

        return dummyNode->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }
};