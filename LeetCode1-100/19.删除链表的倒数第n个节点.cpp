/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
//看到链表倒数操作，就应该想到链表的递归后序遍历。大的框架搭好了，还是有一些问题需要注意的。
//[AC]  
// 这个就是把自己的想法反过来, 从减法到加法，很有意思
    ListNode* PostOrder(int& index,ListNode* head,const int& n)
    {
        if(head == nullptr)
            return nullptr;
        head->next = PostOrder(index,head->next,n);
        ++index;
        return index == n ? head->next:head;  //比如这里就是需要好好总结的，简洁
    }
//不知道自己当初是怎么思考的,考察一番，这个方法也是很具有一般性，值得深入研究。很是巧妙的。
//[AC]
// 注意递归中引用参数的变化。要有把握
    ListNode* UglyCode(ListNode* head,int n)
    {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* prenode = dummyhead;
        for(int i = 0;i <= n;++i)
        {
            prenode = prenode->next;
        }
        ListNode* lastnode = dummyhead;
        while(prenode)
        {
            prenode = prenode->next;
            lastnode = lastnode->next;
        }
        lastnode->next = lastnode->next->next;
        return dummyhead->next;
    }
//留着改进，第一种解法很妙，但自己并没有想到。
//[AC]
    void DFS(ListNode* head,ListNode*& pre,int& n)
    {
        if(head == nullptr)
            return;
        DFS(head->next,head,n);
        --n;
        if(n == 0)
        {
            pre->next = head->next;
        }
    }
    ListNode* GMT(ListNode* head, int n)
    {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* prenode = dummyhead;
        ListNode* temp = nullptr;
        DFS(prenode,temp,n);
        return dummyhead->next;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int index = 0;
        return PostOrder(index,head,n);

        //return UglyCode(head,n);
        //return GMT(head,n);
        
    }
};
// @lc code=end

