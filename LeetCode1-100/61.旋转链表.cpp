/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    //方法一 参见旋转字符串 将原数组复制拼接一份
    //1-2-3-4-5-1-2-3-4-5-Null 旋转几次即从n-k位置开始选择n个节点即可
    //方法二  将链表构造成环
    //[AC]
    ListNode* GMT(ListNode* head,int k)
    {
        if(head == NULL || head->next == NULL || k < 1)
            return head;
        int n = 1;
        ListNode* curnode = head;
        while(curnode->next)
        {
            ++n;    //跳出循环时，n 即为链表的长度
            curnode = curnode->next;
        }
        curnode->next = head;   // 即构造成环
        ListNode* newhead = NULL;
        curnode = head;
        for(int i = 0;i < n - 1- k % n;++i)  // 次数要计算清楚  因为是从0开始的，所以不取等号
        {
            curnode = curnode->next;
        }
        newhead = curnode->next;
        curnode->next = NULL;
        return newhead;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        return GMT(head,k);
    }
};
// @lc code=end

