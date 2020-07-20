/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
// 就要想到扩展，个数的推广。操作方式的推广。如果不是从小到大呢？
//[AC]
    ListNode* Merge(ListNode* p,ListNode* q)
    {
        // if(p == nullptr && q == nullptr)
        // {
        //     return nullptr;
        // }
        // else if(p == nullptr)
        // {
        //     return q;
        // }
        // else if(q == nullptr)
        // {
        //     return p;
        // }
        if(p == nullptr)   // 将上述判断条件转换为下面
            return q;
        else if(q == nullptr)
            return p;
        ListNode* head;
        if(p->val < q->val)
        {
            head = p;
            head->next = Merge(p->next,q);
        }
        else
        {
            head = q;
            head->next = Merge(p,q->next);
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return Merge(l1,l2);
    }
};
// @lc code=end

