/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
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
//如果是满二叉树 则先手必赢，只要放在根节点，剩下的是对称的
//how to consider this question
//the key point: 
    int DFS(TreeNode* root,const int& obj,int& leftnum,int & rightnum)
    {
        if(root == nullptr)
            return 0;
        int left = DFS(root->left,obj,leftnum,rightnum);
        int right = DFS(root->right,obj,leftnum,rightnum);
        if(root->val == obj)
        {
            leftnum = left;
            rightnum = right;
        }
        return 1 + left + right;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int leftnum = 0;
        int rihgtnum = 0;
        DFS(root,x,leftnum,rihgtnum);
        int half = n >> 1; 
        //the key point: make sure the winning condition
        if(leftnum > half || rihgtnum > half || (leftnum + rihgtnum) < half)
            return true;
        else
            return false;
        
    }
};
// @lc code=end

