/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
// 上来应该判断的，而不是直接删除。
    void DFS(TreeNode* root,TreeNode* pre,int key)
    {
        if(root == nullptr)
            return;
        if(root->val == key)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                root = nullptr;
                return;
            }
            else if(root->left == nullptr)
            {
                root->val = root->right->val;
                root = nullptr;
                return;
            }
            if(root->right && pre)
            {
                pre->right
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

    }
};
// @lc code=end

