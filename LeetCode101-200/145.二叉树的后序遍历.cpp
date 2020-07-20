/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
//Morris后序遍历
//手写

    /*
        vector<int> result;
        stack<TreeNode*> mystack;
        TreeNode* curnode = root;
        TreeNode* nextright = NULL;
        while(!mystack.empty() || curnode)
        {
            while(curnode)
            {
                mystack.push(curnode);
                curnode = curnode->left;
            }
            curnode = mystack.top();
            mystack.pop();
            if(curnode->right && curnode->right != nextright)
            {
                mystack.push(curnode);
                curnode = curnode->right;
            }
            else
            {
                result.push_back(curnode->val);
                nextright = curnode;
                curnode = NULL;
            }
        }
        return result;
        */
    }
};
// @lc code=end

