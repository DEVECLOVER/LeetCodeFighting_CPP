/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
//[AC]
    void DFS(TreeNode* root,vector<vector<unsigned long long>>& res,unsigned long long& size,int depth,unsigned long long index)
    {
        if(root == nullptr)
            return;
        if(res.size() <= depth)
            res.push_back(vector<unsigned long long>());
        res[depth].push_back(index);
        // size = max(size,res[depth].back() - res[depth][0] + 1);  // 前序  
        TreeNode* leftnode = root->left;
        TreeNode* rightnode = root->right;
        DFS(leftnode,res,size,depth + 1,2 * index);
        size = max(size,res[depth].back() - res[depth][0] + 1);    // 中序 
        DFS(rightnode,res,size,depth + 1,2 * index + 1);
        // size = max(size,res[depth].back() - res[depth][0] + 1);   // 后序
    }
//[AC]
    int BFS(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        deque<pair<TreeNode*,unsigned long long>> hash;
        hash.push_back(make_pair(root,1));
        unsigned long long size = 1;
        while(!hash.empty())
        {
            int num = hash.size();
            // size = max(size,(hash.back().second - hash.front().second) + 1);     
            for(int i = 0;i < num;++i)
            {
                auto cur = hash.front();
                hash.pop_front();
                TreeNode* leftnode = cur.first->left;
                unsigned long long index = cur.second;
                if(leftnode)
                {
                    hash.push_back(make_pair(leftnode,2 * index));
                }
                TreeNode* rightnode = cur.first->right;
                if(rightnode)
                {
                    hash.push_back(make_pair(rightnode,2 * index + 1));
                }
            }
            // if(!hash.empty())            // 得加判断
            // { 
            //     size = max(size,(hash.back().second - hash.front().second) + 1);  // 为什么不能把这句话放在这儿呢？反思啊，都是教训啊！
            // }
        }
        return size;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return BFS(root);
        // unsigned long long size = 0;
        // vector<vector<unsigned long long>> res;
        // DFS(root,res,size,0,0);
        // return size;
    }
};
// @lc code=end

