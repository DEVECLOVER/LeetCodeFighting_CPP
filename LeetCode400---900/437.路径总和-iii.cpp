/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
//暴力递归超时
    int SubPath(TreeNode* root,int sum)
    {
        if(root == NULL)
            return 0;
        return  ((root->val == sum ? 1 : 0)  + SubPath(root->left,sum - root->val)
                    + SubPath(root->right,sum - root->val));
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        return SubPath(root,sum) + pathSum(root->left,sum)
                + pathSum(root->right,sum);
    }
};
// @lc code=end

