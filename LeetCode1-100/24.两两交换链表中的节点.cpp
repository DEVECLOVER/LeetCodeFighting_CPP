/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swap(ListNode* head)
    {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* prenode = dummyhead;
        while(prenode->next && prenode->next->next)
        {
            ListNode* firnode = prenode->next;
            ListNode* secnode = prenode->next->next;
            prenode->next = secnode;   // 关键的一句话  仔细想想  // 第二次再看，有啥好想的呢
            firnode->next = secnode->next; // 关键就是理清 三者替代的顺序  Pre  fir   sec  按照从前向后分析即可。
            secnode->next = firnode;   // 上述两句不能调换位置，思考
            prenode = prenode->next->next;
        }
        return dummyhead->next;
    }
//[AC]  一次过  一般化   即如果没K个翻转节点呢？
    ListNode* reverseNode(ListNode* head,ListNode* edge)
    {
        if(head == edge || head->next == edge)
            return head;
        ListNode* newhead = reverseNode(head->next,edge);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
    ListNode* GMT(ListNode* head,int k)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* edge = head;
        for(int i = 0;i < k;++i)
        {
            if(edge == nullptr)
                return head;
            edge = edge->next;
        }
        ListNode* newhead = reverseNode(head,edge);
        head->next = GMT(edge,k);
        return newhead;
    }
    ListNode* swapPairs(ListNode* head) {
        //return swap(head);
        return GMT(head,2);
    }
};
// @lc code=end

