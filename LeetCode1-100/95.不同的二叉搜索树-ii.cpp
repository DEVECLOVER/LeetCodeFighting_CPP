/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
//组合思路  联系归并排序
//自己要学的真是太多了，
//第一点，如何将下面的递归思路改编为 dp 实现
//如何按照一般性思维方式求解。即考察新添加的数字的可能位置，
//找到其中的规律不难，关键在于如何把思路变为代码呢？思考问题是否全面呢？
//关于全面性，一定要做好记录，要各个击破，而不是一股脑的写
//后序遍历模式 【AC】
    vector<TreeNode*> GenCore(int start,int end)
    {
        vector<TreeNode*> result;
        if(start > end)
        {
            result.push_back(NULL);
            return result;
        }
        for(int i = start;i<= end;++i)
        {
            vector<TreeNode*> leftnode = GenCore(start,i - 1);
            vector<TreeNode*> rightnode = GenCore(i + 1,end);
            for(auto left : leftnode)
            {
                for(auto right : rightnode)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return n < 1 ? vector<TreeNode*>() : GenCore(1,n);

    }
};
// @lc code=end

