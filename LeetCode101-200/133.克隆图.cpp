/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
//递归理解到一定境界后，已经是在无意识写程序了，你并没有仔细思考其中的细节，但是写出来就是正确的
//但是一旦出错，还是要好好  条分理析
    Node* DFS(Node* root,map<Node*,Node*>& flag)
    {
        if(root == NULL)
            return root;
        if(flag.count(root))
            return flag[root];
        Node* newnode = new Node(root->val);
        flag[root] = newnode;
        for(auto ele : root->neighbors)
        {
            newnode->neighbors.push_back(DFS(ele,flag));
        }
        return newnode;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        map<Node*,Node*> flag;
        // return  DFS(node,flag);

//BFS
        Node* newroot = new Node(node->val);
        queue<Node*> myqueue;
        myqueue.push(node);
        flag[node] = newroot;
        while(!myqueue.empty())
        {
            Node* curnode = myqueue.front();
            myqueue.pop();
            for(auto ele : curnode->neighbors)
            {
                if(!flag.count(ele))
                {
                    flag[ele] = new Node(ele->val);
                    myqueue.push(ele);
                }
                //使用map  正好省略了visited 数组  直接添加即可
                flag[curnode]->neighbors.push_back(flag[ele]);
            }
        }
        return newroot;

    }
};
// @lc code=end

