/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    //二叉搜索树的特点 利用值的大小比较即可  拓展到任意二叉树的最近公共节点

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        int pnum = p->val;
        int qnum = q->val;
        int num = root->val;
        if(pnum > num && qnum > num)
            return lowestCommonAncestor(root->right,p,q);
        else if(pnum < num && qnum < num)
            return lowestCommonAncestor(root->left,p,q);
        else
            return root;
    }
};
// @lc code=end

