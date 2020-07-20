/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
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
    void BSTCore(TreeNode* root,int& sum)
    {
        if(root == NULL)
            return;
        BSTCore(root->right,sum);
        root->val += sum;
        sum = root->val;
        BSTCore(root->left,sum);

    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        BSTCore(root,sum);
        return root;
    }
};
// @lc code=end

