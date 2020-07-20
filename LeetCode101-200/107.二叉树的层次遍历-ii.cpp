/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
// 什么是好题，什么是不好的题。
// 像这道题目不能算是好题，因为他是可以由前向得到的。这种题目纯碎是为了反向思考的。为了逆向而逆向。没有多大的意思
// 虽然当初我利用递归实现了算法，但是现在看来题目并没有多大意味。
    int GetHeight(TreeNode* root)
    {
        return root == NULL ? 0 : 1 + max(GetHeight(root->left),GetHeight(root->right));
    }
//[AC]  记得当时写出了这个程序还是很开心的。因为一步步分析下来，充分运用了前面的知识。
    void AntiOrder(TreeNode* root,vector<vector<int>>& result,int level)
    {
        if(root == NULL)
            return;
        AntiOrder(root->left,result,level - 1);
        AntiOrder(root->right,result,level - 1);
        //第一遍给写成了，下述的判断情况
        //这种情景只适用于完全二叉树，对于高度为3的二叉树，如果第二层左子树为叶子结点
        //添加了一个vector，但是调用的是result[1],就会出现问题。所以改为for循环，都添加完毕
        // if(result.size() < level)
        //     result.push_back(vector<int>());
        for(int i = result.size(); i < level;++i) // 这里判断的是 i < level ,不包含相等。是因为计算高度从1，开始的
            result.push_back(vector<int>());
        result[level - 1].push_back(root->val);  // 这里添加的位置是 level - 1, 和上面的添加个数相对应的。
    }
//同样的道理，如果反着走之字形，也只需要加个就判断即可。
// 当然GMT的解法还是BFS，或者得到前向的解，最后将结果reverse一下即可了。
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        AntiOrder(root,result,GetHeight(root));
        return result;
    }
};
// @lc code=end

