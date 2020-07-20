/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
//整体的分析还是巧妙的
//很值得总结学习
// 再回过头来看，这个方法是很正常的，在对链表有了一定的理解，想出这个方法是应该的。
//[AC]
    ListNode* ReverseKth(ListNode* head,ListNode* edge)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while(cur != edge)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    ListNode* GMT(ListNode* head,int k)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* nextnode = head;
        for(int i = 0;i < k;++i)
        {
            if(nextnode == nullptr)
                return head;
            nextnode = nextnode->next;
        }
        ListNode* newhead = ReverseKth(head,nextnode);
        head->next = GMT(nextnode,k);   // 这一步想明白
        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return GMT(head,k);
    }
};
// @lc code=end

