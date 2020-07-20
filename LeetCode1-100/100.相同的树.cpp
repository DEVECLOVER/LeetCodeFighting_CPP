/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
//想法一，能不能通过遍历方式来判断呢？单纯的某一种遍历方式是不行的。就像我们构造二叉树时，也是根据前后，或者前中
// 也就是说，是得需要两种遍历方式的。
// 当然算上那些nullptr的节点，就是可以一次性遍历的。
// 想法二，通过DFS，每一个节点相互比较即可。
//[AC]
    bool UglyCode(TreeNode* p,TreeNode* q)
    {
        if(p == NULL && q == NULL)
            return true;
        else if(p && q)
        {
            if(p->val != q->val)
                return false;
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        else
        {
            return false;
        }
    }
//[AC]
    bool DFS(TreeNode* p,TreeNode* q)
    {
        if(p == nullptr)
            return q == nullptr;
        if(q == nullptr)
            return p == nullptr;
        return p->val == q->val && DFS(p->left,q->left) && DFS(p->right,q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        //return UglyCode(p,q);
        return DFS(p,q);
    }
};
// @lc code=end

