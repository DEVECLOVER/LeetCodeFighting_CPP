/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
//结合之前的层序遍历  给每层节点添加高度信息  用较大值覆盖原来的值
    void LargeCore(TreeNode* root,vector<int>& result,int level)
    {
        if(root == NULL)
            return;
        if(result.size() <= level)
            result.push_back(INT_MIN);
        if(root->val > result[level])
            result[level] = root->val;
        LargeCore(root->left,result,level + 1);
        LargeCore(root->right,result,level + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        LargeCore(root,result,0);
        return result;
    }
};
// @lc code=end

