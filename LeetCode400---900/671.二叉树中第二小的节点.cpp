/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int GMT(TreeNode* root)
    {
        if(root == nullptr)
            return -1;
        if(root->left == nullptr || root->right == nullptr)
            return -1;
        int leftnum = root->left->val;
        int rightnum = root->right->val;
        int res = max(leftnum,rightnum);
        return  res == root->val ? -1 : res;
    }
    int findSecondMinimumValue(TreeNode* root) {
        return GMT(root);
    }
};
// @lc code=end

