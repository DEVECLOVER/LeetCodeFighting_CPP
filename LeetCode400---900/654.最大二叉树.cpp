/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
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
// [AC]
    int GetIndex(vector<int>& nums,int left,int right)
    {
        int index = left;  // 这里不能赋初值为0 ， 吸取教训
        int temp = nums[left];
        for(int i = left;i <= right;++i)
        {
            if(nums[i] > temp)
            {
                index = i;
                temp = nums[i];
            }
        }
        return index;
    }
    TreeNode* DFS(vector<int>& nums,int left,int right)
    {
        if(left > right)
            return nullptr;
        int index = GetIndex(nums,left,right);
        TreeNode* root = new TreeNode(nums[index]);
        root->left = DFS(nums,left,index - 1);
        root->right = DFS(nums,index + 1,right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int right = nums.size() - 1;
        return DFS(nums,0,right);
    }
};
// @lc code=end

