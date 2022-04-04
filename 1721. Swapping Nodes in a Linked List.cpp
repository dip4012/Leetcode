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
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<ListNode *> arr;
        while (head != nullptr)
        {
            ListNode *next = head->next;
            head->next = nullptr;
            arr.push_back(head);
            head = next;
        }

        swap(arr[k - 1], arr[arr.size() - k]);

        ListNode *newHead = new ListNode();
        ListNode *crawl = newHead;
        for (ListNode *node : arr)
        {
            crawl->next = node;
            crawl = crawl->next;
        }

        return newHead->next;
    }
};