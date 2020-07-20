/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* UglyCode(ListNode* head)
    {
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode* tempNode = newhead;
        while(tempNode->next && tempNode->next->next)
        {
            
            if(tempNode->next->val != tempNode->next->next->val)
            {
               tempNode = tempNode->next;
            }
            else
            {
                int value = tempNode->next->val;
                while(tempNode->next != nullptr && tempNode->next->val == value)
                {
                    tempNode->next = tempNode->next->next;
                }
            }

        }
        return newhead->next;
    }
//[NAC]  作为反面典型，想要利用中间变量，但是指针很容易就断了。好好分析。
    ListNode* GMT(ListNode* head)
    {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* curnode = dummyhead;
        while(curnode->next && curnode->next->next)
        {
            ListNode* tempnode = curnode->next;   // 如果硬要添加变量，还有变量之间转换的问题
            if(tempnode->val == tempnode->next->val)
            {
                int value = tempnode->val;
                while(tempnode && tempnode->val == value)
                    tempnode = tempnode->next;  // 这部出了问题。
            }
            curnode = tempnode;
        }
        return dummyhead->next;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        return UglyCode(head);
        //return GMT(head);
    }
};
// @lc code=end

