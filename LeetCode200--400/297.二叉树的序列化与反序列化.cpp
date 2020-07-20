/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:
//[AC]
    // Encodes a tree to a single string.
    void DFSSerialize(TreeNode* root,string& res)
    {
        if(root == nullptr)
        {
            res += "#,";
            return;
        }
        res += (to_string(root->val) + ',');
        DFSSerialize(root->left,res);
        DFSSerialize(root->right,res);
    }
    string serialize(TreeNode* root) {
        string res = "";
        DFSSerialize(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* DFSDeserialize(string data,int& index)
    {
        if(data[index] == '#')//问题在于没有终止条件啊！
        {
            index += 2;
            return nullptr;
        }
        bool minus = false;
        if(data[index] == '-')
        {
            minus = true;
            ++index;
        }
        int num = 0;
        while(data[index] != ',')
        {
            num = 10 * num + (data[index] - '0');
            ++index;
        }
        if(minus)
            num = -num;
        ++index;
        TreeNode* root = new TreeNode(num);
        root->left  = DFSDeserialize(data,index);
        root->right = DFSDeserialize(data,index);
        return root;
    }
    TreeNode* deserialize(string data) {
        int index = 0;
        return DFSDeserialize(data,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

