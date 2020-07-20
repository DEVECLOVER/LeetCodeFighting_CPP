/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
//[AC]  在I的基础上，添加即可，注意点就是对于不满足的节点pop出去。
// 可以想想，DFS执行完后，nums中还存在元素吗？
//通过这项练习，锻炼自己对递归过程的把握。要能时刻洞悉执行过程中发生的情况。就像之前看到过得，
//别人发现自己的程序出现了bug，请大神指导时，大神闭目沉思，便找到了bug所在。这就是能力。脑子就是程序运行的平台。

    void PathCore(TreeNode* root,int sum,vector<vector<int>>& result,vector<int>& nums)
    {
        if(root == NULL)
            return;
        nums.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum)
        {
            result.push_back(nums);//不可以加return 因为接着执行下面的popback
        }
        PathCore(root->left,sum - root->val,result,nums);
        PathCore(root->right,sum - root->val,result,nums);
        nums.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> nums;
        PathCore(root,sum,result,nums);
        return result;
    }
};
// @lc code=end

