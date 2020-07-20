/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
// 改变题目：对于重复的数字，一次也不留。再者，只留两次。
//[AC]
    ListNode* GMT(ListNode* head)
    {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* prenode = dummyhead;
        while(prenode->next && prenode->next->next)
        {
            ListNode* firnode = prenode->next;
            ListNode* secnode = prenode->next->next;
            int value = firnode->val;
            if(secnode->val == value)
            {
                firnode->next = secnode->next;
            }
            else
            {
                prenode = prenode->next;
            }
        }
        return dummyhead->next;
    }
//[AC]
    ListNode* dummyHead(ListNode* head)
    {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* prenode = dummyhead;
        while(prenode->next && prenode->next->next)
        {
            ListNode* firnode = prenode->next;
            ListNode* secnode = prenode->next->next;
            int value = firnode->val;
            if(secnode->val == value)
                firnode->next = secnode->next;
            else
            {
                prenode = prenode->next;
            }
            
        }
        return dummyhead->next;
    }
//借助哨兵节点，上面的方法是直接改变next的node，并没有真正的删除节点，可以按照这个思路实现一下。
//剑指offer上这题的思考方式是一般性思维方法，但是确实很是繁琐。不够简洁，精炼。有了这个解法，完全没有心情去看书中的代码
//正所谓：如果没有见过太阳，我本可以忍受黑暗。

// 这题可以不用哨兵节点的，因为第一个节点是不会被删除的。但是前面还得加判断，head可能为空
// [AC]
    ListNode* GMT3(ListNode* head)
    {
        if(!head)
            return head;
        ListNode* pre = head;
        int value = head->val;
        while(pre->next)
        {
            if(pre->next->val == value)
            {
                pre->next = pre->next->next;
            }
            else
            {
                pre = pre->next;
                value = pre->val;
            }
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        //return dummyHead(head);
        return GMT3(head);
    }
};
// @lc code=end

