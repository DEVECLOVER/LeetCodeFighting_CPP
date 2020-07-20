/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
//整体思路和 先序和中序构造一样的，关键就是分析好问题，发现子问题，递归实现即可
    TreeNode* GenTreeCore(vector<int>& mid,int mleft,int mright,vector<int>& post,int tleft,int tright)
    {
        if(mleft > mright)
            return NULL;
        TreeNode* newroot = new TreeNode(post[tright]);
        int index = mleft;
        //左神的宝典中是借助于map的定位的，这里采用一般的数组匹配
        for(;index <= mright;++index)
        {
            if(mid[index] == post[tright])
                break;
        }
        //思路捋清楚后，关键点在于下标的对应，是有分析方法的
        newroot->left = GenTreeCore(mid,mleft,index - 1,post,tleft,tleft + index - mleft - 1);
        newroot->right = GenTreeCore(mid,index + 1,mright,post,tleft + index - mleft,tright - 1);
        return newroot;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int mlen = inorder.size();
        int tlen = postorder.size();
        if(mlen < 1 || tlen < 1 || (mlen != tlen))
            return NULL;
        return GenTreeCore(inorder,0,mlen - 1,postorder,0,tlen - 1);
        

    }
};
// @lc code=end

