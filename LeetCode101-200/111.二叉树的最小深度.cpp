/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
//[AC]
    int UglyCode(TreeNode* root)
    {
        if(!root)
            return 0;
        TreeNode* curnode = NULL;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        int height = 0;
        while(!myqueue.empty())
        {
            ++height;
            int len = myqueue.size();
            while(len--)
            {
                curnode = myqueue.front();
                myqueue.pop();
                if(curnode->left == NULL && curnode->right == NULL)
                    return height;
                if(curnode->left)
                    myqueue.push(curnode->left);
                if(curnode->right)
                    myqueue.push(curnode->right);
            }
        }
        return height;
    }
//[AC]
    int BFS(TreeNode* root)
    {
        if(!root)
            return 0;
        queue<pair<TreeNode*, int>> myqueue;
        myqueue.push(make_pair(root,1));
        while(!myqueue.empty())
        {
            TreeNode* curnode = myqueue.front().first;
            int height = myqueue.front().second;
            myqueue.pop();
            if(curnode->left == NULL && curnode->right == NULL)
                return height;
            if(curnode->left)
                myqueue.push(make_pair(curnode->left,height + 1));
            if(curnode->right)
                myqueue.push(make_pair(curnode->right,height + 1));
        }
        return 0;
    }
//[AC]
    int DFS(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        //后序遍历 避免重复判断  根的结果是依赖于左右子树的结果
        int leftheight = minDepth(root->left);
        int rightheight = minDepth(root->right);
        //是或的关系，所以其中必有一个为零 连环相加，避免了判断，不影响结果
        //妙在只使用了一个min函数
        if(root->left == NULL || root->right == NULL)
        {
            return 1 + leftheight + rightheight;
        }
        return 1 + min(leftheight,rightheight);
    }
    int minDepth(TreeNode* root) {
        //return DFS(root);
        //return BFS(root);
        return UglyCode(root);
    }
};
// @lc code=end

