/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    //结合树的右视图，这是左视图，求和即可
    //看看别人的想法，真的很妙，给节点标定左右即可
    //如何想到添加flag标签，可以从BFS入手，如果用BFS解答，如何判断左右呢？也是添加标签
    int LeftSum(TreeNode* root,bool flag)
    {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL && flag)
            return root->val;
        return LeftSum(root->left,true) + LeftSum(root->right,false);
            
    }
// 想着如何把这个标签的方法应用在右视图上，怎么做呢。每一层的最左端。
// 想了下，单纯通过flag是做不到的。前面的方法是添加层数。已经是最好的思路了。
    int sumOfLeftLeaves(TreeNode* root) {
        return LeftSum(root,false);
    }
};
// @lc code=end

