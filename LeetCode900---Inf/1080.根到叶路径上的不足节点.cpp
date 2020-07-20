/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
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
//第一遍思路  有问题
    void Subset(TreeNode* root,int sum,const int limit)
    {
        TreeNode* temp = root;
        if(temp == NULL)
            return ;
        sum += temp->val;
        if(temp->left == NULL && temp->right == NULL && sum < limit)
            temp = NULL;
        Subset(root->left,sum,limit);
        Subset(root->right,sum,limit);
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        Subset(root,0,limit);
        return root;
    }
};
// @lc code=end

