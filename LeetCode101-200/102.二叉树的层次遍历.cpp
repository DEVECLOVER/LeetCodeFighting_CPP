/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
//DFS  BFS 
    void DFS(TreeNode* root,vector<vector<int>>& result,int level)
    {
        if(root == NULL)
            return;
        if(result.size() == level)
            result.push_back(vector<int>()); //这个写法是非常好的，一层一层，同时赋予高度  也可以改为中序 后序
        result[level].push_back(root->val);  // 如果改为中序或者后序，那么创建新的vector的条件就得改变了
        if(root->left)
            DFS(root->left,result,level + 1);
        if(root->right)
            DFS(root->right,result,level + 1);
    }
// [AC]
    void InDFS(TreeNode* root,vector<vector<int>>& res,int level)
    {
        if(root == nullptr)
            return;
        InDFS(root->left,res,level + 1);
        unsigned int size = res.size();
        if(size <= level)   // 这就是添加的条件
        {
            for(int i = size;i <= level;++i)
                res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        InDFS(root->right,res,level + 1);
    }
// [ac]
    void PostDFS(TreeNode* root,vector<vector<int>>& res,int level)
    {
        if(root == nullptr)
            return;
        PostDFS(root->left,res,level + 1);
        unsigned int size = res.size();
        if(size <= level)
        {
            for(int i = size;i <= level;++i)
            {
                res.push_back(vector<int>());
            }
        }
        res[level].push_back(root->val);
        PostDFS(root->right,res,level + 1);
    }
//BFS 【AC】 很容易想到的，这个BFS也是自己经常使用的。
    vector<vector<int>> BFS(TreeNode* root)
    {
        vector<vector<int>> result;
        if(!root)
            return result;
        TreeNode* curnode = root;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while(!myqueue.empty())
        {
            vector<int> nums;
            int len = myqueue.size();
            while(len--)
            {
                curnode = myqueue.front();
                myqueue.pop();
                nums.push_back(curnode->val);
                if(curnode->left)
                    myqueue.push(curnode->left);
                if(curnode->right)
                    myqueue.push(curnode->right);
            }
            result.push_back(nums);

        }
        return result;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        //return BFS(root);
        vector<vector<int>> result;
        PostDFS(root,result,0);
        return result;
    }
};
// @lc code=end

