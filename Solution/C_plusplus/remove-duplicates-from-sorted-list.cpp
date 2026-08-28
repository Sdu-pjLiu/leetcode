#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        if (head == NULL)
        { // 避免边界情况崩溃
            return head;
        }
        ListNode *current = head;
        while (current->next != NULL)
        { //如果下一个节点不是空
            if (current->val == current->next->val)
            {   // 如果下一个节点的值与当前节点的值相等，去除下一个节点
                current->next = current->next->next;
            }
            else
            {   // 移动到下一个节点
                current = current->next;
            }
        }
        return head;
    }
};
