/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
// 找规律，联系Morris遍历。 [AC]
    void GMT(TreeNode* root)
    {
        while(root)
        {
            if(root->left)
            {
                auto tempnode = root->left;
                while(tempnode->right)
                {
                    tempnode = tempnode->right;
                }
                tempnode->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
//[AC]
    void DFS(TreeNode* root)
    {
        if (root == nullptr) 
            return;
        DFS(root->left);
        DFS(root->right);
        if (root->left) 
        {
            auto pre = root->left;
            while (pre->right) 
                pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        //root = root->right;  // 这句话是可有可无的。自己走一遍，发现用不上。
        return;
    }
    void flatten(TreeNode* root) {
        //return GMT(root);
        DFS(root);
    }
};
// @lc code=end

