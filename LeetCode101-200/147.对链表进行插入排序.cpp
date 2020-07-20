/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
//还是很巧妙的，一次遍历即可
    ListNode* GMT(ListNode* head)
    {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* prenode = dummyhead;
        ListNode* curnode = NULL;
        for(auto node = head;node != NULL;)
        {
            curnode = node;
            node = node->next; // 这句话只能放在这里，放在下面和for循环里都会出错，
            //因为curnode = node，后面操作了curnode,也就改变了node的值，所以必须在之前更新值
            if(curnode->val < prenode->val)
                prenode = dummyhead;
            while(prenode->next && prenode->next->val < curnode->val) 
                prenode = prenode->next;
            curnode->next = prenode->next;
            prenode->next = curnode;
            //node = node->next;
        }
        return dummyhead->next;
    }
    ListNode* insertionSortList(ListNode* head) {
        return GMT(head);
    }
};
// @lc code=end

