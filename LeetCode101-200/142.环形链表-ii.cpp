/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
//之前一直困在这里，这种方法虽然可以判断是否存在环，但是不能基于相遇点判断入口点
//这是要十分小心的。【NAC】  比如 : 1->2->1  这个循环，利用下面的做法是不可行的。
    ListNode* FastSlow(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (slow != fast)
        {
            if(fast == nullptr || fast->next == nullptr)
                break;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == nullptr || fast->next == nullptr)
            return nullptr;
        slow = head;
        while(slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
        
    }
//保证fast和slow是出于同一个起点的。
//对于快慢指针的使用，确保起点相同。
//[AC]
    ListNode* Cool(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode* prenode = head;
        ListNode* lastnode = head;
        while(prenode && prenode->next)
        {
            prenode = prenode->next->next;
            lastnode = lastnode->next;
            if(prenode == lastnode)
            {
                break;
            }
        }
        if(prenode == nullptr || prenode->next == nullptr)
            return nullptr;   
       // 到这一步，上面的操作和判断成环是一样的。下面只是加上了寻找入口点。 
       // 按走的步数，而不是点数。这样的话，快指针走的步数是慢指针的两倍。
       // 之前所谓的fastnode = head->next, slow = head; 这是为了保证fastnode的点数是slow的两倍。这是观念的问题。
        prenode = head;
        while(prenode != lastnode)
        {
            prenode = prenode->next;
            lastnode = lastnode->next;
        }
        return prenode;
    }
    ListNode *detectCycle(ListNode *head) {
        return Cool(head);
    }
};
// @lc code=end

