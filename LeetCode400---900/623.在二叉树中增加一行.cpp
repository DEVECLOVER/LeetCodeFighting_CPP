/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
//BFS 即可，每层考察，对d = 1,单独计算，其他边遍历边创建即可


//DFS呢？分析了一下,直接使用即可
//【AC】
    void DFS(TreeNode*& root,int level,const int v,const int d)
    {
        if(root == nullptr)
            return ;
        if(level <= d - 1)
        {
            if(level == d-1)
            {
                TreeNode* newleft = new TreeNode(v);
                TreeNode* newright = new TreeNode(v);
                newleft->left = root->left;
                newright->right = root->right;
                root->left = newleft;
                root->right = newright;
            }
            else
            {
                DFS(root->left,level + 1,v,d);
                DFS(root->right,level + 1,v,d);
            }
        }
    }
    TreeNode* GMT(TreeNode* root,int v,int d)
    {
        if(d == 1)
        {
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }
        DFS(root,1,v,d);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return GMT(root,v,d);
    }
};
// @lc code=end

