/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
//【AC】  题目中说的是完美二叉树，如果不是完美的呢？
    Node* Cool(Node* root)
    {
        if(root == NULL)
            return NULL;
        Node* left = root->left;
        Node* right = root->right;
        //重点就在于，如何实现分别位于左右子树的节点的连接，很妙。观察的到位
        while(left)
        {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
    Node* connect(Node* root) {
       return Cool(root);
    }
};
// @lc code=end

