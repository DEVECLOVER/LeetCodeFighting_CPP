/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
//因为要是平衡BST，所以只能从中间位置开始
//如果不要求平衡，那么个数就是Catalan数了。
//明显的递归，轻松加写意
//[AC]
    TreeNode* BSTCore(vector<int>& nums,int left,int right)
    {
        if(left > right)
        {
            return NULL;
        }
        //int mid = (left + right) >>1;
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BSTCore(nums,left,mid - 1);
        root->right = BSTCore(nums,mid + 1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BSTCore(nums,0,nums.size() - 1);
    }
};
// @lc code=end

