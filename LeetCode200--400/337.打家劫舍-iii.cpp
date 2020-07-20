/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
//暴力递归思路 超时  
    int MaxRob(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int yes = root->val + (root->left == NULL ? 0 : MaxRob(root->left->left) + MaxRob(root->left->right))
                            + (root->right == NULL ? 0 : MaxRob(root->right->left) + MaxRob(root->right->right));
        int no = MaxRob(root->left) + MaxRob(root->right);
        return max(yes,no);
    }
    int MemoMaxRob(TreeNode* root,map<TreeNode*,int>& memo)
    {
        if(root == NULL)
            return 0;
        if(memo[root])
            return memo[root];
        int yes = root->val + (root->left == NULL ? 0 : MemoMaxRob(root->left->left,memo) + MemoMaxRob(root->left->right,memo))
                            + (root->right == NULL ? 0 : MemoMaxRob(root->right->left,memo) + MemoMaxRob(root->right->right,memo));
        int no = MemoMaxRob(root->left,memo) + MemoMaxRob(root->right,memo);
        memo[root] = max(yes,no);
        return memo[root];
    }
    vector<int> dp(TreeNode* root)
    {
        if(root == NULL)
            return vector<int>(2,0);
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        int yes = root->val + left[0] + right[0];
        int no = max(left[0],left[1]) + max(right[0],right[1]);
        vector<int> v = {no,yes};
        return v;
    }
    int rob(TreeNode* root) {
        vector<int> result = dp(root);
        return max(result[0],result[1]);
        // map<TreeNode*,int> memo;
        // return MemoMaxRob(root,memo);
    }
};
// @lc code=end

