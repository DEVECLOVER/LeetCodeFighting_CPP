/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
//在没有认识到快慢指针时，常规思路就是利用hashmap
//[AC]
    bool FastSlow(ListNode* head)
    {
        if(head == nullptr  || head->next == nullptr)
            return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(slow != fast)  // 判断条件是两者是否相等，还可以是fast是否为空。函数体内判断是否相等。
        {
            if(fast == nullptr || fast->next == nullptr)
                return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
    //[AC]
    bool GMT(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return false;
        ListNode* firnode = head;  // 即两者同起点
        ListNode* secnode = head;
        while(firnode && firnode->next)
        {
            firnode = firnode->next->next;
            secnode = secnode->next;
            if(firnode == secnode)
                return true;
        }
        return false;
    }
    bool hasCycle(ListNode *head) {
        //return FastSlow(head);
        return GMT(head);
    }
};
// @lc code=end

