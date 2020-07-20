/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//所谓高度平衡，从中间开始即可
    TreeNode* Recursion(vector<int> nums,int left,int right)
    {
        if(left > right)
            return nullptr;   
        if(left == right)    // 两个判断条件要分开
            return new TreeNode(nums[left]);
        //刚开始将上述两句话，写为了下述，还是思考的不清楚
        //为什么会这样呢？因为脑海中想到的是在归并排序中，left和right的操作，好好总结
        // if(left >= right)   // 比如[0 1 2 3] 按照这个截止条件就是不正确的。
        //     return new TreeNode(nums[left]);
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = Recursion(nums,left,mid - 1);
        root->right = Recursion(nums,mid + 1,right);
        return root;
    }
    TreeNode* BSTCore(ListNode* head)
    {
        vector<int> nums;
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        return Recursion(nums,0,nums.size() - 1);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return BSTCore(head);
    }
};
// @lc code=end

