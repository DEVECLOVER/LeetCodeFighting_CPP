/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
//这个代码是错误的，原因就在于混乱了精调和粗调，不管根节点是否相等，子节点都可以应对。
//这就是问题所在。一旦根节点相等，就应该执行精调，确保之后的各个节点都是相等的。而不是或的关系了。
//【NAC】
    bool GMT(TreeNode* s,TreeNode* t)
    {
        if(s == nullptr && t == nullptr)
            return true;
        else if(s == nullptr || t == nullptr)
            return false;
        else
        {
            // if(s->val == t->val)
            //     return (GMT(s->left,t->left) && GMT(s->right,t->right));
            // else
            // {
            //     return GMT(s->left,t) || GMT(s->right,t);  // 这是重复的。
            // }
            return GMT(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);  // 这都是作为反面典型的。死循环了
        }
    }
//联系判断树的子结构，相同的思路，只是判断条件有所不同
//其实这是粗调和精调的问题：双递归的组合。 这是我的第一想法。分为根节点与否
//【AC】
    bool Part(TreeNode* s,TreeNode* t)
    {
        if(s == nullptr || t == nullptr)
            return s == t;
        if(s->val != t->val)
            return false;
        return Part(s->left,t->left) && Part(s->right,t->right);
    }
    bool GMT2(TreeNode* s,TreeNode* t)
    {
        if(s == nullptr || t == nullptr)
            return s == t;
        return  Part(s,t) || GMT2(s->left,t) || GMT2(s->right,t);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //return SubCore(s,t);
        return GMT2(s,t);
        return GMT(s,t);
    }
};
// @lc code=end

