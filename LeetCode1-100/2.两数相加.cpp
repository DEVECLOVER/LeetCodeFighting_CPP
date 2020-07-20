/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
 //如果数字在链表中的存储不是顺序的，而是逆序的呢？
 //即高位在前，如何求和呢？
 //想到的三种思路：
 //1 转化 翻转链表 变为原题
 //2 数学上推导公式  找到从前向后和从后向前的关系 
 //3 还是按位计算 只是稍微复杂一点 如何向前反馈
 //4 利用栈 出来即是低位
class Solution {
public:
//做到快速有效的分析问题
//第一点 进位问题如何解决 尤其是能不能想法最后一位的进位问题 三位数相加 得到四位数
//第二点 链表为nullptr 如何处理 取值为零
//第三点 如何好的组织代码
//[AC]
    void AddNumsCore(ListNode* p,ListNode* q,int& carry,ListNode*& head)
    {
        if(p == nullptr && q == nullptr)
        {
            return;
        }
        int pnum = (p == nullptr ? 0:p->val);
        int qnum = (q == nullptr ? 0:q->val);
        int sum = pnum + qnum + carry;
        carry = sum / 10;
        head->next = new ListNode(sum %10);
        head = head->next;
        //此处也要加是否为空的判断，不能在参数中写p->next,因为p 可能为nullptr
        p = (p == nullptr ? nullptr : p->next);
        q = (q == nullptr ? nullptr : q->next);
        AddNumsCore(p,q,carry,head);

    }
    ListNode* DFS(ListNode* head1,ListNode* head2)
    {
        //此处递归和迭代的区别不大，而且代码量上没有优势
        int carry = 0;
        ListNode* dummyhead = new ListNode(-1);
        ListNode* nextnode = dummyhead;
        AddNumsCore(head1,head2,carry,nextnode);
        if(carry)
        {
            nextnode->next = new ListNode(carry);
        }
        return dummyhead->next;
    }
//[AC]
    ListNode* GMT(ListNode* head1,ListNode* head2)
    {
        int carry = 0;
        ListNode* dummyhead = new ListNode(-1); // 头指针的使用  就是为了统一
        ListNode* nextnode = dummyhead;
        while(head1 || head2)
        {
            int h1 = (head1 == nullptr) ? 0:head1->val;
            int h2 = (head2 == nullptr) ? 0:head2->val;
            int sum = h1 + h2 + carry;
            carry = sum / 10;
            nextnode->next = new ListNode(sum % 10);
            nextnode = nextnode->next;
            head1 = (head1 == nullptr ? nullptr : head1->next);
            head2 = (head2 == nullptr ? nullptr : head2->next);
        }
        if(carry)
        {
            nextnode->next = new ListNode(carry);
        }
        return dummyhead->next;
    }
//对于定义在链表上的运算，找到规律即可  
//关键在于如何简洁的表达出来。要分析清楚遇到的问题  
//无非就是：两数相加 进位   
//[AC]  
    ListNode* GMT3(ListNode* head1,ListNode* head2)
    {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* newhead = dummyhead;
        int carrybit = 0;
        while(head1 || head2)
        {
            int num1 = head1 == nullptr ? 0 : head1->val;
            int num2 = head2 == nullptr ? 0 : head2->val;
            int res = num1 + num2 + carrybit;
            carrybit = res / 10;
            newhead->next = new ListNode(res % 10);
            head1 = head1 == nullptr ? nullptr : head1->next;
            head2 = head2 == nullptr ? nullptr : head2->next;
            newhead = newhead->next;
        }
        if(carrybit)
            newhead->next = new ListNode(carrybit);
        return dummyhead->next;
    }
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        //return GMT(head1,head2);
        return GMT3(head1,head2);
    }
};
// @lc code=end

