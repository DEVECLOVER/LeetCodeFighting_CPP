/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    //给每层节点分配层数的妙用，拓展到左视图 俯视图呢
    //将之前的层序遍历改写一下即可，遇到同一层的节点，不是添加，而是覆盖之前的元素，很妙
    //当然，最直接的想法还是BFS的层序遍历，取最后的元素
    //【AC】
    void RightView(TreeNode* root,int level,vector<int>& result)
    {
        if(root == NULL)
            return;
        if(result.size() <= level)
            result.push_back(0);  // 每层只需要一个点即可
        result[level] = root->val;
        RightView(root->left,level + 1,result);
        RightView(root->right,level + 1,result);
    }
    vector<int> GMT1(TreeNode* root)
    {
        vector<int> result;
        RightView(root,0,result);
        return result;
    }
//BFS [AC]
    vector<int> GMT2(TreeNode* root)
    {
        vector<int> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> myqueue;
        TreeNode* curnode;
        myqueue.push(root);
        while(!myqueue.empty())
        {
            int len = myqueue.size();
            while (len--)
            {
                curnode = myqueue.front();
                myqueue.pop();
                if(curnode->left)
                    myqueue.push(curnode->left);
                if(curnode->right)
                    myqueue.push(curnode->right);
                if(len == 0)  //  代表是最后一个元素值
                    res.push_back(curnode->val);
            }
        }
        return res;
    }
    vector<int> rightSideView(TreeNode* root) {
        //return GMT1(root);
        return GMT2(root);
    }
};
// @lc code=end

