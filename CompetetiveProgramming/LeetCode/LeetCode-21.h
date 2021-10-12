#pragma once

// Merge two sorted linked listsand return it as a sorted list.The list should be made by splicing together the nodes of
// the first two lists.
#include "../Utility/List.h"
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *headNode = l1;
        if (l1->val > l2->val)
        {
            headNode = l2;
            l2 = l2->next;
        }
        else
        {
            l1 = l1->next;
        }

        ListNode *curr = headNode;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
        }
    }

    int size(ListNode *list)
    {
        int ctr{0};
        while (list)
        {
            ++ctr;
            list = list->next;
        }
    }

    void print_list(ListNode *l)
    {
        while (l)
        {
            std::cout << l->val << ' ';
            l = l->next;
        }
    }
};
