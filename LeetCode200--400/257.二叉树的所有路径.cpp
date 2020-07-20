/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
//这个路径的定义是根节点到叶子结点。总结叶子结点的操作特点，需要单独判断，不要想一蹴而就，有的就不一定能和判空结合到一起。
//在计算树的深度时，没有判断叶子结点。事实上，单独判断也是可以的。
//一个不使用引用，这样最后就不需要减掉了。
//[AC]
    void TreePathCore(TreeNode* root,string str,vector<string>& result)
    {
        if(root == NULL)
            return;
        str += (to_string(root->val) + "->");
        if(root->left == NULL && root->right == NULL)
        {
            str = str.substr(0,str.size() - 2);
            result.push_back(str);
            return;
        }
        TreePathCore(root->left,str,result);
        TreePathCore(root->right,str,result);
        //str = str.Substring(0,str.Length - 1);
    }
    //什么是剪枝  脑子里要有运行图
    //之所以把这两个函数放在一起，是对于递归初学者的，因为刚开始脑子不是很清楚运行过程的
    //这里采用引用，最后还是需要减掉的。
    //[AC]
    void TreePathCoreDeeper(TreeNode* root,string& str,vector<string>& result)
    {
        if(root == NULL)
            return;
        str += (to_string(root->val) + "->");
        if(root->left == NULL && root->right == NULL)
        {
            str = str.substr(0,str.size() - 2);
            result.push_back(str);
        }
        TreePathCore(root->left,str,result);
        TreePathCore(root->right,str,result);
        str = str.substr(0,str.size() - 1);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string str = "";
        vector<string> result;
        //TreePathCoreDeeper(root,str,result);
        TreePathCore(root,str,result);
        return result;
    }
};
// @lc code=end

