/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
 class GMT
{
    public:
       static ListNode* GetMid(ListNode* head)
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
       static ListNode* Reverse(ListNode* head)
        {
            if(head == nullptr || head->next == nullptr)
                return head;
            ListNode* newhead = Reverse(head->next);
            head->next->next = head;
            head->next = nullptr;
            return newhead;
        }
       static ListNode* MergeNode(ListNode* head1,ListNode* head2)
        {
            ListNode* dummyhead = new ListNode(-1);
            ListNode* prenode = dummyhead;
            while(head2)
            {
                prenode->next = head1;
                head1 = head1->next;   // 稍不留神，就会出错啊！指针。
                prenode = prenode->next;
                prenode->next = head2;
                head2 = head2->next;
                prenode = prenode->next;
            }
            prenode->next = head1;
            return dummyhead->next;
        }
};
class Solution {
public:
    ListNode* GetMidNode(ListNode* head)
    {
        ListNode* prenode = head->next;
        ListNode* lastnode = head;
        while(prenode->next && prenode->next->next)
        {
            prenode = prenode->next->next;
            lastnode = lastnode->next;
        }
        return lastnode;
    }

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
    ListNode* MergeNode(ListNode* p,ListNode* q)
    {
        ListNode* prenode = p;
        ListNode* lastnode = NULL;
        while(prenode->next)
        {
            lastnode = q->next;
            q->next = prenode->next;
            prenode->next = q;
            prenode = q->next;
            q = lastnode;
        }
        prenode->next = q;
        return p;
    }
    // 这怕是最一般性思维方法了吧。
    // 当时自己想着如何扩展题目，就料想会有这么一招。交错进行。


//[AC]
    void GMT1(ListNode* head)
    {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;
         ListNode* midnode = GMT::GetMid(head);
         ListNode* rightnode = midnode->next;
         midnode->next = NULL;
         ListNode* leftnode = head;
         rightnode = GMT::Reverse(rightnode);
         head = GMT::MergeNode(leftnode,rightnode);
    }
    void GMT2(ListNode* head)
    {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;
         ListNode* midnode = GMT::GetMid(head);
         ListNode* rightnode = midnode->next;
         midnode->next = NULL;
         ListNode* leftnode = head;
         rightnode = GMT::Reverse(rightnode);
         head = GMT::MergeNode(leftnode,rightnode);
    }
    void reorderList(ListNode* head) {
        GMT1(head);
        //GMT2(head);
    }
};
// @lc code=end

