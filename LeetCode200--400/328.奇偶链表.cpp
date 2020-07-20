/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* UglyCode(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        bool flag = true;
        ListNode* oddhead = NULL;
        ListNode* oddtail = NULL;
        ListNode* evenhead = NULL;
        ListNode* eventail = NULL;
        while(head)
        {
            if(flag)
            {
                if(oddtail == NULL) // 为了避免判断第一个节点，可以使用头结点
                {
                    oddhead = head;
                    oddtail = head;
                }
                else
                {
                    oddtail->next = head;
                    oddtail = oddtail->next;
                }

            }
            else
            {
                if(evenhead == NULL)
                {
                    evenhead = head;
                    eventail = head;
                }
                else
                {
                    eventail->next = head;
                    eventail = eventail->next;
                }
            }
            flag = !flag;
            head = head->next;
        }
        eventail->next = NULL;
        oddtail->next = evenhead;
        return oddhead;
    }
    //[AC]
    ListNode* GMT(ListNode* head)
    {
        ListNode* odddummy = new ListNode(-1);
        ListNode* evendummy = new ListNode(-1);
        ListNode* oddpre = odddummy;
        ListNode* evenpre = evendummy;
        bool flag = true;
        while(head)
        {
            if(flag)
            {
                oddpre->next = head;
                oddpre = oddpre->next;
            }
            else
            {
                evenpre->next = head;
                evenpre = evenpre->next;
            }
            flag = !flag;
            head = head->next;
        }
        evenpre->next = nullptr;  // 考察将这句话去掉，会发生什么
        oddpre->next = evendummy->next;
        return odddummy->next;

    }
    ListNode* oddEvenList(ListNode* head) {
       // return UglyCode(head);
       return GMT(head);
    }
};
// @lc code=end

