/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
// 这个解法是很容易想到的。首先是后序遍历，是没问题的。
// 只要不是从上到下的，首先要想到后序遍历
//[AC]
    int PathSumCore(TreeNode* root,int& maxnum)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftsum = max(PathSumCore(root->left,maxnum),0);
        int rightsum = max(PathSumCore(root->right,maxnum),0);
        maxnum = max(maxnum,leftsum + rightsum + root->val); // 之所以可以直接比较这两个，因为自下而上，原先想着要再多个比较呢,因为可能存在负数
        return (max(leftsum,rightsum) < 0? root->val : max(leftsum,rightsum) + root->val);
    }
    int maxPathSum(TreeNode* root) 
    {
        int maxsum = INT_MIN;
        PathSumCore(root,maxsum);
        return maxsum;
    }
};
// @lc code=end

