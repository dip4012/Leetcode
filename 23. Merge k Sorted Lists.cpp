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
    ListNode *merge2Lists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr || list2 == nullptr)
            return list1 == nullptr ? list2 : list1;

        ListNode *list3;
        if (list1->val <= list2->val)
        {
            list3 = list1;
            list3->next = merge2Lists(list1->next, list2);
        }
        else
        {
            list3 = list2;
            list3->next = merge2Lists(list1, list2->next);
        }
        return list3;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;

        int interval = 1;
        while (interval < lists.size())
        {
            for (int i = 0; i < lists.size() - interval; i += interval * 2)
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            interval *= 2;
        }
        return lists[0];
    }
};