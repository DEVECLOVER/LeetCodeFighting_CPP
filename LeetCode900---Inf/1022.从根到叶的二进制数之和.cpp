/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    void SumCore(TreeNode* root,int bit,int& sum)
    {
        if(root == NULL)
            return;
        bit = ((bit << 1) + root->val);//思路是没有问题，关键点在于叶子节点退出，不再继续计算
        if(root->left == NULL && root->right == NULL)
        {
            sum += bit;
            return;
        }
        SumCore(root->left,bit,sum);
        SumCore(root->right,bit,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        SumCore(root,0,sum);
        return sum;
    }
};
// @lc code=end

