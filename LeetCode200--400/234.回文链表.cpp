/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* Reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* newhead = Reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    bool GMT(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* lefthead = head;
        ListNode* righthead = head->next;
        while(righthead->next && righthead->next->next)
        {
            righthead = righthead->next->next;
            lefthead = lefthead->next;
        }
        righthead = lefthead->next;
        lefthead->next = NULL;
        lefthead = head;
        righthead = Reverse(righthead);
        while(lefthead)
        {
            if(lefthead->val != righthead->val)
                return false;
            lefthead = lefthead->next;
            righthead = righthead->next;
        }
        return true;
    }
    // [AC]
    void IsPal(ListNode* head,ListNode*& pre,bool& flag)
    {
        if(head == nullptr)
            return;
        if(!flag)
            return;
        IsPal(head->next,pre,flag);
        if(head->val == pre->val)
        {
            pre = pre->next;
        }
        else
        {
            flag = false;
        }
    }
    bool isPalindrome(ListNode* head) 
    {
        // bool flag = true;
        // ListNode* pre = head;
        // IsPal(head,pre,flag);
        // return flag;
        return GMT(head);
    }
};
// @lc code=end

