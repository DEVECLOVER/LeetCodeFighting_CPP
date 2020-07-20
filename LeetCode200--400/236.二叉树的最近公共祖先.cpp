/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
//非常妙的解法，自己想不到
//要好好反思，这题还是要有分类的思想。所给的两个节点是否在同一个子树上。
//[AC]
    TreeNode* Cool(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root == NULL || root == p || root == q)
            return root;
        TreeNode* leftnode = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightnode = lowestCommonAncestor(root->right,p,q);
        if(leftnode && rightnode)
            return root;
        return leftnode == NULL ? rightnode : leftnode;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return Cool(root,p,q);
    }
};
// @lc code=end

