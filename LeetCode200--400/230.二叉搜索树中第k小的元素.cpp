/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
//DFS   很简单的思路嘛  一气呵成
//[AC]
    void DFS(TreeNode* root,int& res,int& k)
    {
        if(root == nullptr)
            return;
        DFS(root->left,res,k);
        --k;
        if(k == 0)
        {
            res = root->val;
            return;
        }
        DFS(root->right,res,k);
    }
    int Cool(TreeNode* root,int k)
    {
        int res = 0;
        DFS(root,res,k);
        return res;
    }
//BFS 
//从题解来看，似乎用了stack就是dfs ，queue就是BFS了
//以后写遍历，就用Morris 不要用传统的，就是要掌握别人不掌握的
//[AC]
    void InOrder(TreeNode* root,vector<int>& result)
    {
        TreeNode* curnode = root;
        TreeNode* nextnode = NULL;
        while(curnode)
        {
            nextnode = curnode->left;
            if(nextnode)
            {
                while(nextnode->right && nextnode->right != curnode)
                {
                    nextnode = nextnode->right;
                }
                if(nextnode->right)
                {
                    nextnode->right = NULL;
                }
                else
                {
                    nextnode->right = curnode;
                    curnode = curnode->left;
                    continue;
                }
            }
            result.push_back(curnode->val);
            curnode = curnode->right;
        }
    }
    int GMT(TreeNode* root,int k)
    {
        //应该加入一些判断条件  k 的大小 root 为null
        vector<int> result;
        InOrder(root,result);
        return result[k - 1];
    }
//相关的题目，还有第K大的值，总结套路。
//一看，我并没有知道总共有多少个数字，但是我却能知道第K大的数。神不神奇呢？
//也就是说，关键在于数据的组织形式。一般给出的数组，按照大小排好的，即使不排好的，我们可以很容易找到第K大的
//现在换了组织形式，将数存在二叉树上，也可以很容易找到某个数。
//重要的不是空间里的元素，而是定义在空间上的运算法则。
//延伸到社会科学，重要的不是各种肤色的人（黑人 黄种人 白人），而是人的组织关系。
    int kthSmallest(TreeNode* root, int k) {
        //return GMT(root,k);
        return Cool(root,k);
    }
};
// @lc code=end

