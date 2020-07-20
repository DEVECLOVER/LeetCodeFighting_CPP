/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
//第一想法，是遍历G数组，而不是遍历链表，
//原因在于我读错了题目，想着G中的子序列必须是连续的
//如果在面试时，得和面试官交流，确保读懂题意，通过举例子的方式
    int numComponents(ListNode* head, vector<int>& G) {
        map<int,int> hashmap;
        bool flag = true;//是否为开头的标志位
        for(auto num : G)
            ++hashmap[num];
        ListNode* curnode = head;
        int count = 0;
        while(curnode)
        {
            if(hashmap.count(curnode->val) && flag)//只有在第一次开始找到时，中间件个数才加一
            {
                flag = false;
                ++count;
            }
            else if(!hashmap.count(curnode->val) && !flag) //只有在找到中间件已经触发的条件下，没有找到连续的，才断开，重新开始
                flag = true;
            curnode = curnode->next;
        }
        return count;

    }
};
// @lc code=end

