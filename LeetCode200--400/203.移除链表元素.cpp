/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* curnode = dummyhead;
        while(curnode->next)
        {
            if(curnode->next->val == val)
            {
                curnode->next = curnode->next->next;
            }
            else
            {
                curnode = curnode->next;
            }
        }
        return dummyhead->next;

    }
};
// @lc code=end

