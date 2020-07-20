/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
 //方法一  tree inplace 判断   
 //借助数据容器  queue or stack
 //将左先序 右先序 存储起来 ，比较即可，但是得遍历两遍 效率不高
 // 通过左右序列比较时不行的，除非将null指针也存入。
class Solution {
public:
//[AC]
    bool SymCore(TreeNode* p,TreeNode* q)
    {
        // 方法一  这种判断总是太笨重
        // if(!p && !q)
        //     return true;
        // if(!p || !q || (p->val != q->val))
        //     return false;
        // 方法二
        if(p == nullptr)
            return q == nullptr;
        if(q == nullptr)
            return p = nullptr;
        if(p->val != q->val)
            return false;
        return SymCore(p->left,q->right) 
        && SymCore(p->right,q->left); 
    }
//[AC]
    bool GMT(TreeNode* root)
    {
         queue<TreeNode*> myqueue;
        TreeNode* prenode = NULL;
        TreeNode* lastnode = NULL;
        myqueue.push(root);
        myqueue.push(root);
        while(!myqueue.empty())
        {
            prenode = myqueue.front();
            myqueue.pop();
            lastnode = myqueue.front();
            myqueue.pop();
            if(!prenode && !lastnode) continue;
            if(!prenode || !lastnode || (prenode->val != lastnode->val))
                return false;
            myqueue.push(prenode->left);
            myqueue.push(lastnode->right);
            myqueue.push(prenode->right);
            myqueue.push(lastnode->left);
        }
        return true;
     }
    bool isSymmetric(TreeNode* root) 
    {
       //return SymCore(root,root);
        return GMT(root);
    }
};
// @lc code=end

