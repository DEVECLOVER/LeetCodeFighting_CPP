/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
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
//从分枝数来证明偶数节点不存在满二叉树
//第一想法，找规律，因为每次添加的只能是奇数
//新增的肯定是两个，找到各个叶子结点即可，但是得去掉重复的可能
    vector<TreeNode*> FBTCore(int N,map<int,vector<TreeNode*>>& res)
    {
        if(res.count(N))
            return res[N];
        if(N < 2)
        {
            res[N].push_back(new TreeNode(0));
            return res[N];
        }
        //不能取到  N ，因为这里循环取的是 左子树的值
        for(int i = 1;i < N;i += 2)
        {
            vector<TreeNode*> leftpart = FBTCore(i,res);
            vector<TreeNode*> rightpart = FBTCore(N - 1 - i,res);
            for(auto left : leftpart)
            {
                for(auto right : rightpart)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    res[N].push_back(root);
                }
            }
        }
        return res[N];
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        //必须加括号
        if((N & 1) == 0)
            return vector<TreeNode*>();
        map<int,vector<TreeNode*>> res;
        FBTCore(N,res);
        return res[N];
    }
};
// @lc code=end

