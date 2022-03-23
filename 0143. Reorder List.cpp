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
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;

        stack<ListNode *> stk;
        ListNode *slow = head, *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = nullptr;
        while (fast != nullptr)
        {
            ListNode *t = fast;
            fast = fast->next;
            t->next = nullptr;
            stk.push(t);
        }

        slow = head;
        while (slow != nullptr && !stk.empty())
        {
            ListNode *t = slow->next;
            slow->next = stk.top();
            stk.pop();
            slow = slow->next;
            slow->next = t;
            slow = t;
        }
    }
};