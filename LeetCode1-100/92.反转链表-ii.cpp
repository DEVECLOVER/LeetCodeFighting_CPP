/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
// 【AC】  一气呵成，绝妙的方法 妙在循序渐进 分析转化的思维
    ListNode* ReverseCore(ListNode* head,ListNode*& lastnode,int m)
    {
        if(m == 1)
        {
            lastnode = head->next;
            return head;
        }
        ListNode* newhead = ReverseCore(head->next,lastnode,m - 1);
        head->next->next = head;
        head->next = lastnode;
        return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == 1)
        {
            ListNode* lastnode = nullptr;
            return ReverseCore(head,lastnode,n);
        }
        head->next = reverseBetween(head->next,m - 1,n - 1);
        return head;
    }
};
// @lc code=end

