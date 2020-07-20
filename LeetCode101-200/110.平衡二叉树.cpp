/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    //自底向上，想到后序遍历
    //[AC]
    // 第二遍看，不要学这种直接在后面加一的操作，就是说，前面计算高度时都是将加一放在后面的，所以要统一。
    int BalancedCore(TreeNode* root,bool& flag)
    {
        if(root == NULL)
            return 0;
        int leftheight = BalancedCore(root->left,flag) + 1; //这个加1操作是很好的
        int rightheight = BalancedCore(root->right,flag) + 1;
        if(abs(leftheight - rightheight) > 1)
            flag = false;
        return max(leftheight,rightheight);
    }
// 这样似乎更好理解一些，返回子树的高度。
//[AC]  这里注意的是，返回的是高度值，但是最后判断的是bool变量，这里是把flag作为参数更新的。
    int DFS(TreeNode* root,bool& flag)
    {
        if(!flag)
            return 0;
        if(root == NULL)
            return 0;
        int leftheight = BalancedCore(root->left,flag); 
        int rightheight = BalancedCore(root->right,flag);
        if(abs(leftheight - rightheight) > 1)
            flag = false;
        return 1 + max(leftheight,rightheight);  // 这就是计算树的高度
    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        //BalancedCore(root,flag);
        DFS(root,flag);
        return flag;
    }
};
// @lc code=end

