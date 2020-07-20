/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
// 一般性思维方法即可  首先考察总的个数 n 。分两步走：如果k不小于n，简单的很；如果k 小于n :利用整除即可
// 原本以为会是轻松加写意的一道题，没想到有很多细节是需要打磨的。
// 虽然自己最初的想法是没问题的，但是细节，还是细节啊！！！
//[AC]
    vector<ListNode*> GMT(ListNode* root,int k)
    {
        int num = 0;
        vector<ListNode*> res;
        ListNode* cur = root;
        while(cur)
        {
            res.push_back(new ListNode(cur->val));
            ++num;
            cur = cur->next;
        }
        if(k >= num)
        {
            for(int i = num;i < k;++i)   // 第一点，这里要不要加等号
            {
                res.push_back(nullptr);
            }
            return res;
        }
        else
        {
            int index = 0;
            vector<ListNode*> newres(k,new ListNode(-1));  // 初始化头结点，刚开始没有想到
            int quotient = num / k;
            int reminder = num % k;
            for(int i = 0;i < k;++i)
            {
                ListNode* pre = newres[i];     // 利用影子，开始没有想到
                for(int j = 0;j < quotient;++j)
                {
                    pre->next = res[index++];
                    pre = pre->next;
                }
                if(reminder > 0)
                {
                    pre->next = res[index++];
                    --reminder;
                }
                newres[i] = newres[i]->next;   // 最后还需要回归，没有提前考虑到
            }

            return newres;
        }
        
    }
   
    vector<ListNode*> GMT3(ListNode* root,int k)
    {
        int num = 0;
        vector<ListNode*> res;
        ListNode* cur = root;
        while(cur)
        {
            ListNode* next = cur->next;   
            cur->next = nullptr;
            res.push_back(cur);   // 变化在于，不是新构造节点。
            ++num;
            cur = next;
        }
        if(k >= num)
        {
            for(int i = num;i < k;++i)   // 第一点，这里要不要加等号
            {
                res.push_back(nullptr);
            }
            return res;
        }
        else
        {
            int index = 0;
            vector<ListNode*> newres(k,new ListNode(-1));  // 初始化头结点，刚开始没有想到
            int quotient = num / k;
            int reminder = num % k;
            for(int i = 0;i < k;++i)
            {
                ListNode* pre = newres[i];     // 利用影子，开始没有想到
                for(int j = 0;j < quotient;++j)
                {
                    pre->next = res[index++];
                    pre = pre->next;
                }
                if(reminder > 0)
                {
                    pre->next = res[index++];
                    --reminder;
                }
                newres[i] = newres[i]->next;   // 最后还需要回归，没有提前考虑到
            }

            return newres;
        }
        
    }
   
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        //return GMT(root,k);
        return GMT3(root,k);
    }
};
// @lc code=end

