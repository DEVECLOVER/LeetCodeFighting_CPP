/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
//借助队列即可
//充要条件就是，一旦出现null,后面就不能再出现非null节点了
    bool BFS(TreeNode* root)
    {
        queue<TreeNode*> myqueue;
        TreeNode* curnode = root;
        myqueue.push(curnode);
        while(!myqueue.empty())
        {
            curnode = myqueue.front();
            myqueue.pop();
            if(curnode == nullptr)
                break;
            myqueue.push(curnode->left);
            myqueue.push(curnode->right);
        }
        while(!myqueue.empty())
        {
            curnode = myqueue.front();
            myqueue.pop();
            if(curnode != nullptr)
                return false;
        }
        return true;
    }
    bool BFS2(TreeNode* root)
    {
        bool lastnull = false;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        TreeNode* curnode;
        while(!myqueue.empty())
        {
            curnode = myqueue.front();
            myqueue.pop();
            if(curnode->left)
            {
                if(lastnull)
                    return false;
                myqueue.push(curnode->left);
            }
            else
            {
                lastnull = true;
            }
            if(curnode->right)
            {
                if(lastnull)
                    return false;
                myqueue.push(curnode->right);
            }
            else
            {
                lastnull = true;
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        //return BFS(root);
        return BFS2(root);
    }
};
// @lc code=end

