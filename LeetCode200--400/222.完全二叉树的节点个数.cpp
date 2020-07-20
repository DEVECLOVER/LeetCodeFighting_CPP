/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
// 这种方法确实是不很容易想到的。
    int GetTreeHeight(TreeNode* root)
    {
        int num = 0;
        while(root)
        {
            ++num;
            root = root->left;
        }
        return num;
    }
    int RecursionCore(TreeNode* root,int level,int obj)
    {
        if(level == obj)
            return 1;
        //很多细节需要考虑清楚  这里的高度的变化   obj是固定的，树的高度，level则是运动的，扫描层数
        if(GetTreeHeight(root->right) == obj - level)
        {
            return (1 << (obj - level)) + RecursionCore(root->right,level + 1,obj);
        }
        else
        {
            return (1 << (obj - 1 - level)) + RecursionCore(root->left,level + 1,obj);
        }
    }
// 一般直接遍历，累加个数即可了.[AC]
    void GMT(TreeNode* root,int& num)
    {
        if(root == nullptr)
            return ;
        ++num;
        GMT(root->left,num);
        GMT(root->right,num);
    }
// 而上面一种方法是适用于任意二叉树，也就没有把握住完全二叉树的特点。
// 所以也是不好的。完全二叉树什么特点呢？除了最后一层，上面是等比数列的，所以主要任务就是计算出最后一层的个数。

    int countNodes(TreeNode* root) {
        //return root == NULL ? 0 : RecursionCore(root,1,GetTreeHeight(root));
        int num = 0;
        GMT(root,num);
        return num;
    }
};
// @lc code=end

