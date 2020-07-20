/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
// 一般的思路，先一次性遍历，然后利用二分查找即可
    bool flag = false;
// 如果直接使用递归解决呢？每个遍历，然后判断gap是否存在，但是耗时
    void DFS(TreeNode* root,int k,bool& flag)
    {
        if(flag)
            return;
        if(root == nullptr)
            return ;
        if(k < root->val)
            DFS(root->left,k,flag);
        else if(k > root->right)
            DFS(root->right,k,flag);
        flag = true;
        return;
    }
// 
    bool findTarget(TreeNode* root, int k) {
        DFS(root,k - root->val) 
    }
};
// @lc code=end

