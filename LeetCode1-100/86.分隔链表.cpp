/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
// 【AC】 一般性思维方法，即是如何一次性遍历呢？因为要求是给链表分类重组，那就定义不同种类的
// 要考虑到扩展性：如果变换个分类的规则呢？根据奇偶性呢？根据丑数呢？所以又该如何做呢？
// 就可以使用函数指针作为参数了。
    ListNode* GMT(ListNode* head,int x)
    {
        ListNode* smallhead = new ListNode(-1);
        ListNode* largehead = new ListNode(-1);
        ListNode* curnode = head;
        ListNode* cursmall = smallhead;
        ListNode* curlarge = largehead;
        while(curnode)
        {
            if(curnode->val < x)
            {
                cursmall->next = curnode;
                cursmall = cursmall->next;
            }
            else
            {
                curlarge->next = curnode;
                curlarge = curlarge->next;
            }
            curnode = curnode->next;
         }
         curlarge->next = curnode;
         cursmall->next = largehead->next;
         return smallhead->next;
    }
    ListNode* partition(ListNode* head, int x) {
        return GMT(head,x);
    }
};
// @lc code=end

