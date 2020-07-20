/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
//[AC]  这个更加简洁有力
    int SumCore(TreeNode* root,int sum)
    {
        if(root == NULL)
            return 0;
        sum = 10 * sum + root->val;
        //这个退出条件很关键，不是root为null退出  一定要抓住叶子结点这个条件
        if(root->left == NULL && root->right == NULL)
            return sum;
        return SumCore(root->left,sum) + SumCore(root->right,sum);
    }
//[NAC]  作为反面典型。
    void DFS(TreeNode* root,int& sum,int val)
    {
        if(root == NULL)   // 这就是问题所在，因为null了，不一定就是叶子结点了，不能执行加操作，如果只有单个子节点呢？所以后面的除以2也是不行的。只适用于满二叉树。
        {
            sum += val;
            return;
        }
        DFS(root->left,sum,10 * val + root->val);
        DFS(root->right,sum,10 * val + root->val);
    }
    int GMT(TreeNode* root)
    {
        int sum = 0;
        DFS(root,sum,0);
        return sum >> 1;
    }
    //[AC]  一次过  第一想法
    void DFS3(TreeNode* root,int& sum ,int temp)
    {
        if(root == nullptr)
            return;
        temp = 10 * temp + root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            sum = sum + temp;
        }
        DFS3(root->left,sum,temp);
        DFS3(root->right,sum,temp);
    }
    int sumNumbers(TreeNode* root) {
        //return SumCore(root,0);
        //return GMT(root);
        int sum = 0;
        DFS3(root,sum,0);
        return sum;
    }
};
// @lc code=end

