/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
// 对于二叉树：分为根节点  左子树  右子树  ，就是他们的各种组合情况而已  这是第一思维
//[AC]
    TreeNode* GetNode(TreeNode* root,const bool& flag)
    {
        if(root == nullptr)
            return nullptr;
        TreeNode* leftnode  = GetNode(root->left,flag);
        TreeNode* rightnode = GetNode(root->right,flag);
        TreeNode* obj = root;
        if(flag)
        {
            if(leftnode && leftnode->val > obj->val)
                obj = leftnode;
            if(rightnode && rightnode->val > obj->val)
                obj = rightnode;
        }
        else
        {
            if(leftnode && leftnode->val < obj->val)
                obj = leftnode;
            if(rightnode && rightnode->val < obj->val)
                obj = rightnode;
        }
        return obj;
        
    }
    void GMT(TreeNode* root)
    {
        if(root == nullptr)
            return;
        TreeNode* leftnode = GetNode(root->left,true);
        TreeNode* rightnode = GetNode(root->right,false);
        if(leftnode && rightnode)
        {
            if(leftnode->val > rightnode->val)
            {
                swap(leftnode->val,rightnode->val);
            }
        }
        if(leftnode)
        {
            if(leftnode->val > root->val)
                swap(leftnode->val,root->val);
        }
        if(rightnode)
        {
            if(rightnode->val < root->val)
                swap(rightnode->val,root->val);
        }
        GMT(root->left);
        GMT(root->right);
    }
//第二种思路：二叉搜索树中序遍历是有序的，一旦交换了元素，必有两个不满足递增的
//[AC] Morris 中序遍历实现
    void UglyCode(TreeNode* root)
    {
        TreeNode* curnode = root;
        TreeNode* nextnode = NULL;
        TreeNode* prenode = NULL;
        TreeNode* lastnode = NULL;
        TreeNode* node = new TreeNode(INT_MIN);
        while(curnode)
        {
            nextnode = curnode->left;
            if(nextnode)
            {
                while(nextnode->right && nextnode->right != curnode)
                {
                    nextnode = nextnode->right;
                }
                if(nextnode->right == NULL)
                {
                    nextnode->right = curnode;
                    curnode = curnode->left;
                    continue;
                }
                else
                {
                    nextnode->right = NULL;
                }
            }
            // 方法一
            // if(!prenode && (node->val > curnode->val))
            // {
            //     prenode = node;
            // }
            // if(prenode && (node->val > curnode->val))  // 事实上，这两个if会连续执行的。
            // {
            //     lastnode = curnode;  // 重点在于两次赋值的节点不同，这一点也是自己当初没有思考到的
            // }
           // 方法二  这个赋值思路就和DFS中的一样了。
           if(node && node->val > curnode->val)
           {
               if(!prenode)
               {
                   prenode = node;
                   lastnode = curnode;
               }
               else
               {
                   lastnode = curnode;
               }
           }
            node = curnode;
            curnode = curnode->right;
        }
        int num = prenode->val;
        prenode->val = lastnode->val;
        lastnode->val = num;
    }
//[AC]
    void DFS(TreeNode* root,TreeNode** fir,TreeNode** sec,TreeNode** pre)
    {
        if(root == nullptr)
            return ;
        DFS(root->left,fir,sec,pre);
        if(*pre && root->val < (*pre)->val)
        {
            if(*fir == nullptr)
            {
                *fir = *pre;
                *sec = root;
            }
            else
                *sec = root;
        }
        *pre = root;
        DFS(root->right,fir,sec,pre);
    }
//[AC]
    void DFS1(TreeNode* root,TreeNode*& fir,TreeNode*& sec,TreeNode*& pre)
    {
        if(root == nullptr)
            return ;
        DFS1(root->left,fir,sec,pre);
        if(pre && root->val < pre->val)
        {
            if(fir == nullptr)
            {
                fir = pre;    // 这是关键点，这里的赋值是考虑交换的是相邻的情况
                sec = root;
            }
            else
                sec = root;   //这里考虑的是非相邻的情况
        }
        pre = root;
        DFS1(root->right,fir,sec,pre);
    }
// 改变题目，如果交换了多组呢？如何在保持结构不变的情况下，最快恢复二叉树
// 二叉搜索树的逆序数为零。一旦交换了，逆序数改变。假设经过N次交换，问能否经过少于N次交换恢复二叉树。

    void recoverTree(TreeNode* root) {
        UglyCode(root);
        // TreeNode* fir = nullptr;
        // TreeNode* sec = nullptr;
        // TreeNode* pre = nullptr;
        // // DFS1(root,fir,sec,pre);
        // // int temp = fir->val;
        // // fir->val = sec->val;
        // // sec->val = temp;
        // DFS(root,&fir,&sec,&pre);
        // int temp = fir->val;
        // fir->val = sec->val;
        // sec->val = temp;
        //GMT(root);
    }
};
// @lc code=end

