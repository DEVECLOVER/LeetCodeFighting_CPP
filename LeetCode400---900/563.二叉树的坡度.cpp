/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int DFS(TreeNode* root,int& res)
    {
        if(root == nullptr)
            return 0;
        int leftnum = DFS(root->left,res);
        int rightnum = DFS(root->right,res);
        int steep = abs(leftnum - rightnum);
        res += steep;
        return root->val + leftnum + rightnum;
    }
    int Tilt(TreeNode* root)
    {
        int res = 0;
        DFS(root,res);
        return res;
    }
    int findTilt(TreeNode* root) {
        return Tilt(root);
    }
};
// @lc code=end

