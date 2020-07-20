/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
//因为二叉搜索树，且要求读取的时间为O(1),
//第一想法是中序遍历，将数据存储起来,一次过
//【AC】
    vector<int> nums;
    int index;
    int len;
    void InOrder(TreeNode* root)
    {
        if(root == nullptr)
            return ;
        InOrder(root->left);
        nums.push_back(root->val);
        InOrder(root->right);
    }
    BSTIterator(TreeNode* root) {
        InOrder(root);
        index = 0;
        len = nums.size();
    }
    
    /** @return the next smallest number */
    int next() {
        return nums[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < len;
    }
// 上述方法是简单的，但是不满足题目的要求，如何改进呢？第一种方法是一开始就将所有的点加载进去了。如果要保证
// 有限的存储空间，我们就得受控的添加元素，而不是一次性添加。我们知道较小的元素在父节点的左子节点。
// 那么问题就转换为如何添加右子节点了。想想也是不难的。
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

