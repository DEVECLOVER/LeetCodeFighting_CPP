/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        //Morris 先序遍历
        vector<int> result;
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
                    result.push_back(curnode->val);
                    curnode = curnode->left;
                    continue;
                }
            }
            else
            {
                result.push_back(curnode->val);
            }
            curnode = curnode->right;
        }
        return result;
        //用栈模拟递归即可
        /*
        vector<int> result;
        stack<TreeNode*> mystack;
        TreeNode* curnode = root;
        while(!mystack.empty() || curnode)
        {
            while(curnode)
            {
                mystack.push(curnode);
                result.push_back(curnode->val);
                curnode = curnode->left;
            }
            curnode = mystack.top();
            mystack.pop();
            curnode = curnode->right;
        }
        return result;
*/
    }
};
// @lc code=end

