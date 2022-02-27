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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode dummyNode = ListNode(0);
        ListNode *temp = &dummyNode;
        int count = 1;

        while (count < left)
        {
            temp->next = head;
            temp = temp->next;
            head = head->next;
            count++;
        }

        stack<ListNode *> s;
        while (count <= right)
        {
            s.push(head);
            head = head->next;
            count++;
        }

        while (!s.empty())
        {
            ListNode *node = s.top();
            s.pop();
            temp->next = node;
            temp = temp->next;
        }

        while (head != nullptr)
        {
            temp->next = head;
            temp = temp->next;
            head = head->next;
        }

        temp->next = nullptr;

        return dummyNode.next;
    }
};