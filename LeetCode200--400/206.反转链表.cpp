/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
//[AC]
    ListNode* GMT1(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* newhead = GMT1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
    //[AC]
    ListNode* GMT2(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    ListNode* reverseList(ListNode* head) {
       // return GMT1(head);
       return GMT2(head);
    }
};
// @lc code=end

