/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
    Node* GetNextNode(Node* root)
    {
        while(root->next)
        {
            if(root->next->left)
                return root->next->left;
            if(root->next->right)
                return root->next->right;
            root = root->next;
        }
        return NULL;
    }
    // [AC]  这么分析思路很清晰。能不能合二为一呢？
    Node* DFS(Node* root)
    {
        if(root == NULL)
            return NULL;
        //静下心来，把逻辑理清楚，不要急于求成
        if(root->left && root->right)
        {
            root->left->next = root->right;
            root->right->next = GetNextNode(root);
        }
        else if(root->left)
        {
            root->left->next = GetNextNode(root);
        }
        else if(root->right)
        {
            root->right->next = GetNextNode(root);
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
//因为这是同层指向。BFS即可。
// 充分利用了前面的思路，很赞【AC】
    void DFS3(Node*& root,vector<vector<Node*>>& res,int level)
    {
        if(root == nullptr)
            return;
        if(res.size() <= level)
        {
            res.push_back(vector<Node*>());
        }
        if(!res[level].empty())
        {
            res[level].back()->next = root;
        }
        res[level].push_back(root);
        DFS3(root->left,res,level + 1);
        DFS3(root->right,res,level + 1);
    }
// 如果单纯利用BFS的思路也是可以的。
//[AC]
    Node* GMT(Node* root)
    {
        if(root == nullptr)
            return nullptr;
        queue<Node*> myqueue;
        myqueue.push(root);
        while(!myqueue.empty())
        {
            int size = myqueue.size();
            Node* pre = nullptr;
            Node* curnode = nullptr;
            for(int i = 0;i < size;++i)
            {
                curnode = myqueue.front();
                myqueue.pop();
                if(curnode->left)
                    myqueue.push(curnode->left);
                if(curnode->right)
                    myqueue.push(curnode->right);
                if(pre)
                {
                    pre->next = curnode;
                }
                pre = curnode;
            }
        }
        return root;
    }
//可以另一种DFS，因为是同一层的，借助前面的层序输出即可。所需的空间为树的高度。
    Node* connect(Node* root) {
       //return  DFS(root);
    //    vector<vector<Node*>> res;
    //    DFS3(root,res,0);
    //    return root;
    return GMT(root);
    }
};
// @lc code=end

