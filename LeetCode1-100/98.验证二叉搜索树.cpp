/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
//第一遍自己的思路
//存在的问题 1  不够简洁，判断条件太多，没有整合
//没有完整的分析好问题，只是比较了根和左右两节点的情况 这一点在分析问题时要考虑清楚
//每个要判断的上下界是变化的，
//【NAC】
    bool GMT(TreeNode* root)
    {
        if(root == NULL)
            return true;
        if(root->left == NULL && root->right == NULL) //这个判断有必要加吗？自己分析
            return true;
        if(root->left && root->left->val >= root->val)
            return false;
        if(root->right && root->right->val <= root->val)
            return false;
        return isValidBST(root->left) && isValidBST(root->right);  // 问题在什么地方呢？这是因为每个节点的上界和下界是同一个的，这是不正确的，应该是变动的。
    }
//非常精简的方法，改进了上述的方法
//【AC】
    bool IsValidCore(TreeNode* root,long low,long high)
    {
        if(root == NULL)
            return true;
        int num = root->val;
        if(num <= low || num >= high)
            return false;
        return IsValidCore(root->left,low,num) && IsValidCore(root->right,num,high);
    }
//当然第一想法应该是中序遍历，然后判断数组是不是单调增的
//如果第一想法不是这个，是不应该的，因为对于二叉搜索树，中序遍历有序是本能
//【AC】
    void InOrder(TreeNode* root,vector<int>& res)
    {
        if(root == nullptr)
            return;
        InOrder(root->left,res);
        res.push_back(root->val);
        InOrder(root->right,res);
    }
/// [AC] 通过Morris中序遍历实现
    bool InOrder_Morris(TreeNode* root)
    {
        vector<int> res;
        TreeNode* prenode = root;
        TreeNode* lastnode = nullptr;
        while(prenode)
        {
            lastnode = prenode->left;
            if(lastnode)
            {
                while(lastnode->right && lastnode->right != prenode)
                    lastnode = lastnode->right;
                if(lastnode->right == nullptr)
                {
                    lastnode->right = prenode;
                    prenode = prenode->left;
                    continue;
                }
                else
                {
                    lastnode->right = nullptr;
                }
                
            }
            res.push_back(prenode->val);
            prenode = prenode->right;
        }
        int len = res.size();
        for(int i = 0;i < len - 1;++i)
        {
            if(res[i] >= res[i + 1])
                return false;
        }
        return true;
    }
    bool GMT2(TreeNode* root)
    {
        vector<int> res;
        InOrder(root,res);
        int len = res.size();
        for(int i = 0;i < len - 1;++i)
        {
            if(res[i] >= res[i + 1])
                return false;
        }
        return true;
    }
// 【AC】
    bool Cool(TreeNode* root,long low,long high)
    {
        if(root == nullptr)
            return true;
        if(root->val <= low || root->val >= high)  // 这里带等号的，不能是相等的。
        {
            return false;
        }
        return Cool(root->left,low,root->val) && Cool(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
        //return IsValidCore(root,LONG_MIN,LONG_MAX); // 因为节点中的值可能为INT_MIN  INT_MAX
        //return GMT2(root);
        //return InOrder_Morris(root);
        return Cool(root,LONG_MIN,LONG_MAX);
    }
};
// @lc code=end

