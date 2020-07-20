/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
//自己对于树的遍历的理解还是不够深入
//分析问题时总是局限在子树的遍历，没有意识到，整体性
//不能是前序遍历，存在太多的重复求和，只能是后序遍历
    int SumCore(TreeNode* root,map<int,int>& hashmap,int& maxcount)
    {
        if(root == NULL)
            return 0;
        int leftsum = SumCore(root->left,hashmap,maxcount);
        int rightsum = SumCore(root->right,hashmap,maxcount);
        int sum = root->val + leftsum + rightsum;
        ++hashmap[sum];
        maxcount = max(maxcount,hashmap[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxcount = 0;
        map<int,int> hashmap;
        vector<int> res;
        SumCore(root,hashmap,maxcount);
        for(auto ele : hashmap)
        {
            if(ele.second == maxcount)
                res.push_back(ele.first);
        }
        return res;
    }
};
// @lc code=end

