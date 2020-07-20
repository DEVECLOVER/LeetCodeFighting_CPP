/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
//只是把自己的第一想法写了出来，一次过，但是时间和空间复杂度不太优化，还能不能改进呢？
//【AC】
    TreeNode* DFS(TreeNode* t1,TreeNode* t2)
    {
        if(t1 == nullptr && t2 == nullptr)
            return nullptr;
        TreeNode* root;
        if(t1 == nullptr)
        {
            root = new TreeNode(t2->val);
            root->left = DFS(nullptr,t2->left);
            root->right = DFS(nullptr,t2->right);
        }
        else if(t2 == nullptr)
        {
            root = new TreeNode(t1->val);
            root->left = DFS(t1->left,nullptr);
            root->right = DFS(t1->right,nullptr);
        }
        else
        {
            root = new TreeNode(t1->val + t2->val);
            root->left = DFS(t1->left,t2->left);
            root->right = DFS(t1->right,t2->right);
        }
        return root;
    }
    TreeNode* GMT(TreeNode* t1,TreeNode* t2)
    {
        return DFS(t1,t2);
    }
//看了题解，他们是把节点共享了，而不是都创建新的节点
//时间比上述快一些，【AC】
    TreeNode* DFS2(TreeNode* t1,TreeNode* t2)
    {
        if(t1 == nullptr)
            return t2;
        if(t2 == nullptr)
            return t1;
        TreeNode* root;
        root = new TreeNode(t1->val + t2->val);
        root->left = DFS(t1->left,t2->left);
        root->right = DFS(t1->right,t2->right);
        return root;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //return GMT(t1,t2);
        return DFS2(t1,t2);
    }
};
// @lc code=end

