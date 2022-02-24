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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;

        ListNode *ans = head;
        ListNode *prev = head;
        ListNode *temp = head->next;
        ListNode *temp1 = ans;
        while (temp)
        {
            if (temp->val != prev->val)
            {
                temp1->next = temp;
                temp1 = temp1->next;
                prev = temp;
            }
            temp = temp->next;
        }

        temp1->next = nullptr;
        return ans;
    }
};