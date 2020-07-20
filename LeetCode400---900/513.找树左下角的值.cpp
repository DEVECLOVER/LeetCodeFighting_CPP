/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
//慢慢积累如何分析问题
//第一点，最后一行，高度信息，前面的每层最大值  每层的最左值
//第二点，最左边，位置信息，前面的左叶子之和
    void LeftValue(TreeNode* root,int level,int& prelevel,int& num)
    {
        if(root == NULL)
            return ;
        if(level > prelevel)
        {
            num = root->val;
            prelevel = level;
        }
        LeftValue(root->left,level + 1,prelevel,num);
        LeftValue(root->right,level + 1,prelevel,num);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        int num = 0;
        int prelevel = -1;
        LeftValue(root,0,prelevel,num);
        return num;
    }
};
// @lc code=end

