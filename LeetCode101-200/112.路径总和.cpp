/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
//减法实现 【AC】
    void PathCore(TreeNode* root,int sum,bool& flag)
    {
        if(flag)
            return;
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL && root->val == sum)
        {
            flag = true;
            return;
        }
        PathCore(root->left,sum - root->val,flag);
        PathCore(root->right,sum - root->val,flag);
    }
// 加法实现  【AC】
    void DFS(TreeNode* root,int sum,bool& flag,const int& obj)
    {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr && sum + root->val == obj)
        {
            flag = true;
            return;
        }
        DFS(root->left,sum + root->val,flag,obj);
        DFS(root->right,sum + root->val,flag,obj);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        bool flag = false;
        PathCore(root,sum,flag);
        //DFS(root,0,flag,sum);
        return flag;
    }
};
// @lc code=end

