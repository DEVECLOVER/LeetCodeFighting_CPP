/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
//经过几题，自己对于二叉树的遍历还是有一定的误解，还得进一步分析
    void MinDiffCore(TreeNode* root,int& mindiff,int& prevalue)
    {
        if(root == NULL)
            return;
        MinDiffCore(root->left,mindiff,prevalue);
        if(prevalue != -1)
            mindiff = min(mindiff,root->val - prevalue);
        prevalue = root->val;
        MinDiffCore(root->right,mindiff,prevalue);
    }
    int getMinimumDifference(TreeNode* root) {
        int mindiff = INT_MAX;
        int prevalue = -1;//不可初始化为0，因为根节点可能为0
        MinDiffCore(root,mindiff,prevalue);
        return mindiff;
    }
};
// @lc code=end

