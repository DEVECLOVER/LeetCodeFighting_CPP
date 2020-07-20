/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
 //方法一 在遍历是直接转变方向
 //方法二 遍历时 固定的从左到右，遍历完成后，将奇数层数据翻转即可
 //可以借用 双端队列 or 普通的栈和队列
 //方法还是DFS 和 BFS
class Solution {
public:
//自己之前写过栈和队列的实现，也写过使用双端队列的方式
//一直没想过这种方式。确实很好的思路，转化为前面的层序遍历，抓住两者的联系即可。
//[AC]
    void DFS(TreeNode* root,vector<vector<int>>& result,int level)
    {
        if(root == NULL)
            return;
        if(level == result.size())
            result.push_back(vector<int>());
        //不要忘记加括号啊！！！  level & 1 == 0  执行 1 == 0
        if((level & 1) == 0)
        {
            result[level].push_back(root->val);
        }
        else
        {
            result[level].insert(result[level].begin(),root->val);// 即在前面添加即可
        }
        //注意点 不要将下述的level + 1  写为 ++level，这样level本身就改变了
        // 事实上，下面的两个if判断是不必要的。
        if(root->left)
            DFS(root->left,result,level + 1);
        if(root->right)
            DFS(root->right,result,level + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        DFS(root,result,0);
        return result;
    }
};
// @lc code=end

