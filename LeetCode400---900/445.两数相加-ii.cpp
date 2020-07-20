/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
//这两个方法都是很容易想到的，一般性思维方式
//第一个是，转化思想，因为做过了两数相加，拿到这道题，应该要想到翻转的
//第二个是，正常的分析思路，元素存到栈里，先取出来的便是低位的数据，实现即可
//
    ListNode* Reverse(ListNode* head)
    {
        ListNode* prenode = NULL;
        ListNode* nextnode = NULL;
        while(head)
        {
            nextnode = head->next;
            head->next = prenode;
            prenode = head;
            head = nextnode;
        }
        return prenode;
    }
    //【AC】
    ListNode* OldMethod(ListNode* l1,ListNode* l2)
    {
        ListNode* newl1 = Reverse(l1);
        ListNode* newl2 = Reverse(l2);
        ListNode* dummyhead = new ListNode(-1);
        ListNode* curnode = dummyhead;
        int carrybit = 0;
        while(newl1 || newl2)
        {
            int num1 = newl1 == NULL ? 0 : newl1->val;
            int num2 = newl2 == NULL ? 0 : newl2->val;
            int sum = carrybit + num1 + num2;
            curnode->next = new ListNode(sum % 10);
            curnode = curnode->next;
            carrybit = sum / 10;
            newl1 = newl1 == NULL ? NULL : newl1->next;
            newl2 = newl2 == NULL ? NULL : newl2->next;
        }
        if(carrybit)
            curnode->next = new ListNode(carrybit);
        curnode = Reverse(dummyhead->next);
        return curnode;
    }
    // good job 自己想法一次过  【AC】
     ListNode* ByStack(ListNode* l1,ListNode* l2)
    {
        stack<int> s1;
        stack<int> s2;
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carrybit = 0;
        int temp = 0;
        ListNode* pre = NULL;
        while(!s1.empty() && !s2.empty())
        {
            int temp = carrybit + s1.top() + s2.top();
            ListNode* curnode = new ListNode(temp % 10);
            carrybit = temp / 10;
            curnode->next = pre;
            pre = curnode;
            s1.pop();
            s2.pop();
        }
        while(!s1.empty())
        {
            int temp = carrybit + s1.top();
            ListNode* curnode = new ListNode(temp % 10);
            carrybit = temp / 10;
            curnode->next = pre;
            pre = curnode;
            s1.pop();
        }
        while(!s2.empty())
        {
            int temp = carrybit + s2.top();
            ListNode* curnode = new ListNode(temp % 10);
            carrybit = temp / 10;
            curnode->next = pre;
            pre = curnode;
            s2.pop();
        }
        if(carrybit)
        {
            ListNode* curnode = new ListNode(carrybit);
            curnode->next = pre;
            pre = curnode;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //return OldMethod(l1,l2);
        return ByStack(l1,l2);

    }
};
// @lc code=end

