/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode* Merge(ListNode* p,ListNode* q)
    {
        if(p == nullptr)
        {
            return q;
        }
        if(q == nullptr)
        {
            return p;
        }
        ListNode* head;
        if(p->val < q->val)
        {
            head = p;
            head->next = Merge(p->next,q);
        }
        else
        {
            head = q;
            head->next = Merge(p,q->next);
        }
        return head;
    }
    ListNode* MergeCore(vector<ListNode*>& lists,int left,int right)
    {
        if(left >= right)  // 这里包含等于  联系其他不包含等于的。因为是left mid 而不是left mid - 1
        {
            return lists[left];
        }
        //int mid = (left + right) >> 1;
        int mid = left + ((right - left) >> 1);
        ListNode* leftlist = MergeCore(lists,left,mid);  // 
        ListNode* rigthlist = MergeCore(lists,mid + 1,right);
        return Merge(leftlist,rigthlist);   // 后序遍历  
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1)
        {
            return nullptr;
        }
        int len = lists.size() - 1;
        return MergeCore(lists,0,len);
    }
};
// @lc code=end

