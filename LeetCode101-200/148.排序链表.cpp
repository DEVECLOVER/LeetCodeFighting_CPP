/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
class Way
{
    public:
        static ListNode* FindMidNode(ListNode* head)
        {
            if (head == nullptr)
            {
                return nullptr;
            }
            ListNode* firstNode = head;
            ListNode* secNode = head;
            while (firstNode && firstNode->next)
            {
                firstNode = firstNode->next->next;
                secNode = secNode->next;
            }
            return secNode;
        }
        static ListNode* GetMidNode(ListNode* head)
        {
            ListNode* firnode = head;
            ListNode* secnode = head;
            while(firnode->next && firnode->next->next)
            {
                firnode = firnode->next->next;
                secnode = secnode->next;
            }
            return secnode;
        }
        static ListNode* MergeNode(ListNode* p,ListNode* q)
        {
            ListNode* dummyhead = new ListNode(-1);
            ListNode* cur = dummyhead;
            while(p && q)
            {
                if(p->val < q->val)
                {
                    cur->next = p;
                    p = p->next;
                }
                else
                {
                    cur->next = q;
                    q = q->next;
                }
                cur = cur->next;
            }
            cur->next = p == nullptr ? q : p;
            return dummyhead->next;
        }
};
class Solution {
public:
//想法很好想，MergeSort，但是如何很好的实现代码，
//第一想法模仿数组的归并排序，看了题解，把两者结合的
    ListNode* UglyCOde(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* lasthead = slow->next;
        slow->next = nullptr;
        ListNode* leftNode = sortList(head);
        ListNode* rightNode = sortList(lasthead);
        //可以将下述的合并单独作为一个功能函数
        ListNode* newhead = new ListNode(-1);
        ListNode* curnode = newhead;
        while(leftNode && rightNode)
        {
            if(leftNode->val < rightNode->val)
            {
                curnode->next = leftNode;
                leftNode = leftNode->next;
            }
            else
            {
                curnode->next = rightNode;
                rightNode = rightNode->next;                
            }
            curnode = curnode->next;
        }
        curnode->next = leftNode == nullptr ? rightNode : leftNode;
        return newhead->next;
    }

// [AC ] 哈哈，一次性通过
    ListNode* GMT(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* midnode = Way::GetMidNode(head);
        ListNode* lastnode = midnode->next;
        midnode->next = nullptr;
        ListNode* leftnode = GMT(head);
        ListNode* rightnode = GMT(lastnode);
        return Way::MergeNode(leftnode,rightnode);
    }
    ListNode* sortList(ListNode* head) {
        return GMT(head);
    }
};
// @lc code=end

