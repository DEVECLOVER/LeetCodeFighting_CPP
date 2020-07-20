/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
//【AC】  对于这种递归遍历要有整体观念
    void InOrder(TreeNode* root,vector<int>& result)
    {
        if(root == NULL)
            return ;
        InOrder(root->left,result);
        result.push_back(root->val);
        InOrder(root->right,result);

    }
//【AC】
    vector<int> InOrderByIteration(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> con;
        TreeNode* curnode = root;
        // 仔细考察与上述的关系
        while(!con.empty() || curnode)   // 这句话相当于 if(root == null)
        {
            while(curnode)              // 相当于 InOrder(root->left);
            {
                con.push(curnode);
                curnode = curnode->left;
            }
            curnode = con.top();         // 依次对应
            con.pop();
            result.push_back(curnode->val);
            curnode = curnode->right;   //  ……InOrder(root->right)

        }
        return result;
    }
// Morris 【AC】 非常妙的方法。
//对于这类图形问题算法，一定要画图分析，除非自己对他非常熟悉了。
//还要记住，每次画图分析过后，一定要总结有什么注意点，提醒自己下一次。
//【AC】
	vector<int> InOrder_Morris(TreeNode* root)
	{
        vector<int> res;
		TreeNode* prenode = root;
		TreeNode* lastnode = nullptr;  // 这里的prenode和lastnode的关系，联系二叉搜索树转双向链表。都在于找到关系
		while (prenode)
		{
			lastnode = prenode->left;
			if (lastnode)
			{
				//理解后一半的条件  使用场景
				while (lastnode->right && lastnode->right != prenode)
				{
					lastnode = lastnode->right;
				}
				if (lastnode->right == nullptr)
				{
					lastnode->right = prenode;
					prenode = prenode->left;
					continue;
				}
				else
				{
					//配合lastnode->right = prenode;
					lastnode->right = nullptr;
                    //将节点信息复原回去
				}
			}
			res.push_back(prenode->val); // 注意点
			prenode = prenode->right;  // 树接到右子树上了，所以每次选择右子树
		}
        return res;
	}
//第二遍编写  【AC】
    vector<int> InorderMorris2(TreeNode* root)
    {
        if(root == nullptr)
            return {};
        vector<int> res;
        TreeNode* prenode = root;
        TreeNode* nextnode = nullptr;
        while(prenode)
        {
            nextnode = prenode->left;
            if(nextnode)
            {
                while(nextnode->right && nextnode->right != prenode)
                    nextnode = nextnode->right;
                if(nextnode->right == nullptr)
                {
                    nextnode->right = prenode;
                    prenode = prenode->left;
                    continue;
                }
                else
                {
                    nextnode->right = nullptr;
                }
                
            }
            res.push_back(prenode->val);
            prenode = prenode->right;
        }
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //return InOrderByIteration(root);
        //return InOrder_Morris(root);
        return InorderMorris2(root);
    }
};
// @lc code=end

