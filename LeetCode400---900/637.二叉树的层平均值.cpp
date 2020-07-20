/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
//BFS自然很简单就可以完成了
//【AC】
    vector<double> GMT1_BFS(TreeNode* root)
    {
        vector<double> res;
        queue<TreeNode*> myqueue;
        TreeNode* curnode;
        myqueue.push(root);
        while(!myqueue.empty())
        {
            int len = myqueue.size();
            double sum = 0;
            for(int i = 0;i < len;++i)            
            {
                curnode = myqueue.front();
                myqueue.pop();
                if(curnode->left)
                    myqueue.push(curnode->left);
                if(curnode->right)
                    myqueue.push(curnode->right);
                sum += curnode->val;
            }
            res.push_back(sum / len);
        }
        return res;
    }
//DFS 也是可以的，但是需要多层的vector，能不能再简化呢，只需要一个vector。
    vector<double> averageOfLevels(TreeNode* root) {
        return GMT1_BFS(root);
    }
};
// @lc code=end

