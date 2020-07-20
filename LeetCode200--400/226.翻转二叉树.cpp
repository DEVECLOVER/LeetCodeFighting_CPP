/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    //如果改为偶数层才翻转呢  
    //BFS 层序遍历即可，对于树的遍历，层序遍历几乎都是可行的。
    //DFS 
    void SwapNode(TreeNode*& p,TreeNode*& q)
    {
        TreeNode* curnode = p;
        p = q;
        q = curnode;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        SwapNode(root->left,root->right);
        invertTree(root->right);
        invertTree(root->left);
        return root;

    }
};
// @lc code=end

