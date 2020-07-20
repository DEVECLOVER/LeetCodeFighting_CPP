/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
//第一想法，因为做过了剑指offer，采用上面的方法
//再想，可以使用hashmap，存储即可
// [AC]
    Node* GMT_Map(Node* head)
    {
        Node* curnode = head;
        map<Node* , Node*> hashmap;
        while(curnode)
        {
            hashmap[curnode] = new Node(curnode->val);
            curnode = curnode->next;
        }
        curnode = head;
        while(curnode)
        {
            hashmap[curnode]->next = hashmap[curnode->next];
            hashmap[curnode]->random = hashmap[curnode->random];
            curnode = curnode->next;
        }
        return hashmap[head];
    }
//这种方法是怎么样的分析思路呢？可以总结应用在那些问题上呢？
//这是复杂链表的复制，如果是普通的链表呢？要一步步的分析。
//同样的分析方法还有：链表的翻转，翻转指定的一部分，定区间的翻转等等，都是基于最初的问题不断加深的
    Node* swordoffer(Node* head)
    {
        if (head == nullptr)
            return head;

        //遍历原链表 遍历过程中插入新副本节点
        Node* cur = head;
        while (cur)
        {
            Node* node = new Node(cur->val);
            Node* next = cur->next;
            node->next = next;
            cur->next = node;
            cur = next;
        }

        //遍历原链表 对新副本节点设置random指针
        cur = head;
        while (cur)
        {
            cur->next->random = cur->random ? cur->random->next : nullptr;
            if(cur->next)
                cur = cur->next->next;// 这一点应该判断一下
            else
            {
                break;
            }
            
        }

        //分离出原链表与新副本链表
        cur = head;
        Node* new_cur = head->next;
        Node* res = new_cur;
        while (cur)
        {
            cur->next = cur->next->next;   // 经过上述的复制，链表长度肯定是偶数的。所以cur->next->next 肯定是有效的。不用判断cur->next是否为nullptr
            cur = cur->next; 

            new_cur->next = cur ? cur->next : nullptr;
            new_cur = new_cur->next;
        }

        return res; //注意：不能再返回head->next了，head已经是分离后的原链表
    }
    Node* SO3(Node* head)
    {
        if(head == nullptr)
            return nullptr;
        Node* cur = head;
        while(cur)
        {
            Node* nextnode = cur->next;
            Node* newnode = new Node(cur->val);
            newnode->next = nextnode;
            cur->next = newnode;
            cur = nextnode;
        }
        cur = head;
        while(cur)
        {
            cur->next->random = cur->random ? cur->random->next : nullptr;
            if(cur->next)
                cur = cur->next->next;
            else
            {
                break;
            }
            
        }
        cur = head;
        Node* newhead = cur->next;
        Node* newcur = newhead;
        while(cur)
        {
            cur->next = cur->next->next;
            cur = cur->next;
            newcur->next = cur ? cur->next : nullptr;
            newcur = newcur->next;
        }
        return newhead;
    }
    Node* copyRandomList(Node* head) {
        //return GMT_Map(head);
        //return swordoffer(head);
        return SO3(head);
    }
};
// @lc code=end

