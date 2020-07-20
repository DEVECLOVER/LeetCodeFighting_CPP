/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
//注意点：下标的计算，利用中序，快速算出前序的左子树的范围，以及右子树
// 中序 ： LDR  前序  ：DLR  
    TreeNode* GenTreeCore(vector<int>& pre,int pleft,int pright,vector<int>& mid,int mleft,int mright)
    {
        // TreeNode* newroot = new TreeNode(pre[pleft]);
        // if(pleft == pright)
        //     return newroot;
        //上述的结束条件使用于 中序序列和后序序列构造新树  对先序和中序，不满足
        //因为pleft == pright 时，不能直接退出，右子树可能还有值。
        //上述语句对中后适用，就是因为能保证节点的平衡性
        //也有的用mleft 和mright作为终止条件的，
        if(pleft > pright)   //
            return NULL;
        TreeNode* newroot = new TreeNode(pre[pleft]);
        int index = mleft;
        for(;index <= mright;++index) // 这一段查找的代码，可以利用hashmap，快速定位
        {
            if(pre[pleft] == mid[index])
                break;
        }
        newroot->left = GenTreeCore(pre,pleft + 1, pleft + index - mleft,mid,mleft,index - 1);
        newroot->right = GenTreeCore(pre,pleft + index - mleft + 1,pright,mid,index + 1,mright);
        return newroot;
    }
    TreeNode* GMT(vector<int>& preorder,vector<int>& inorder)
    {
        if(preorder.size() < 1 || inorder.size() < 1)  // 类似这种先验判断，要养成习惯。
            return NULL;
        if(preorder.size() != inorder.size())
            return nullptr;
        int len = preorder.size() - 1;
        return GenTreeCore(preorder,0,len,inorder,0,len);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return GMT(preorder,inorder);
    }
};
// @lc code=end

