/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
//联系最小深度，代码量没有这个短小  为什么呢？
//再联系到计算完全二叉树的节点数，采用加法还是减法，加法的代码量更少。
//[AC]
    int DFS(TreeNode* root)
    {
        return root == NULL ? 0 : 1 + max(DFS(root->left),DFS(root->right));            
    }
//之所以要再写一遍后续遍历的，是为了联系最小深度的代码。
//两者有什么区别和联系呢？可以只将下面的max换为min吗？为什么不行呢？什么情况下就可以呢？
// 虽然直接将max替换为min不能解决最小高度树的问题，但是这是一中思路。
//[AC]
    int DFS2(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int leftheight = DFS2(root->left);
        int rightheight = DFS2(root->right);
        return 1 + max(leftheight,rightheight); //想想如果出现节点只有一个子节点会怎样。这就是问题所在
        // 如果只是替换为min，那么当只有一个子节点时，会认为是叶子结点。因为取的是min,min的结果是0啊。
    }
//什么时候采用后序遍历呢？当目标对象定义是从上到下时（也就是目标存在方向时，比如高度），就可以采用后序
    //BFS的话，直接在添加一个高度变量即可，没遍历一层，高度加一
    int maxDepth(TreeNode* root) {
        //return DFS(root);
        return DFS2(root);
    }
};
// @lc code=end

