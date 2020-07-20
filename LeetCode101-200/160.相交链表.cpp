/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
// 对于刚接触hashmap的人，可能拿到需要查找的题目，都想要使用，
//这个题目也不例外，当然可以hashmap一下
// 【AC】
    ListNode* Map(ListNode* head1,ListNode* head2)
    {
        map<ListNode*,bool> hashmap;
        ListNode* curnode = head1;
        while(curnode)
        {
            hashmap[curnode] = true;
            curnode = curnode->next;
        }
        curnode = head2;
        while(curnode)
        {
            if(hashmap[curnode])
                return curnode;
            curnode = curnode->next;
        }
        return nullptr;
    }
//这是在剑指offer中看到的方法，自己现在还记得，写出来一次过
//可以从理论给予证明，走路程，速度一样
//[ AC]
    ListNode* Cool(ListNode* head1,ListNode* head2)
    {
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        while(cur1 != cur2)
        {
            cur1 = cur1 ? cur1->next : head2;
            cur2 = cur2 ? cur2->next : head1;
        }
        return cur1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //return Map(headA,headB);
        return Cool(headA,headB);
    }
};
// @lc code=end

