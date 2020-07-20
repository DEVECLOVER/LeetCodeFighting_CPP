/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache {
public:
//题目即是根据项目要求设计一种数据结构
//如何分析呢？要根据要求：
//特点如下：插入快 查找快  删除快  数据有顺序
//自己手里有什么工具呢？
//哈希表：查找快
//链表：插入块 删除快 有顺序  但是查找慢
    struct Cache
    {
        public:
            int key;
            int val;
            Cache* pre;
            Cache* next;
            Cache(int k,int value):key(k),val(value),pre(nullptr),next(nullptr)
            {

            }
    };

    int lengh;
    int cap;
    Cache* head;
    Cache* tail;
    map<int,Cache*> hashmap;
    LRUCache(int capacity) {
        lengh = 0;
        cap = capacity;
        head = new Cache(-1,-1);
        tail = new Cache(-1,-1);
        tail->pre = head;
        head->next = tail;
    }
    
    int get(int key) {
        if(!hashmap.count(key))
            return -1;
        //首先得到这个节点，
        Cache* curnode = hashmap[key];
        //然后将此节点从链表当前位置删除
        curnode->next->pre = curnode->pre;
        curnode->pre->next = curnode->next;

        //删除节点写法的 反面典型  
        // node->prev = head;
        // node->next = head->next;
        // node->prev->next = node;
        // node->next->prev = node;
        //接着，将该节点加到开头，即虚拟头结点head的后面
        head->next->pre = curnode;
        curnode->next = head->next;
        curnode->pre = head;
        head->next = curnode;
        //返回节点值
        return curnode->val;
    }
    
    void put(int key, int value) {
        if(hashmap.count(key))
        {
            //首先改变节点的值
            Cache* curnode = hashmap[key];
            curnode->val = value;
            //接着思路和前面的get一样的，删除在链表的位置，加到开头
            curnode->next->pre = curnode->pre;
            curnode->pre->next = curnode->next;
            head->next->pre = curnode;
            curnode->next = head->next;
            curnode->pre = head;
            head->next = curnode;
        }
        else
        {
            Cache* curnode = new Cache(key,value);
            if(lengh < cap)
            {
                head->next->pre = curnode;
                //最开始写为了下述，花费了半个小时的找bug
                //具体是将别人通过的代码，copy过来，将自己的代码复制在他上面，一一比对
                //最开始肯定是读自己的代码有没有问题，但是觉得没有问题
                //便只好一一比对了，吸取教训啊。
                //curnode->next = curnode;
                curnode->next = head->next;
                curnode->pre = head;
                head->next = curnode;
                ++lengh;
                hashmap[key] = curnode;
            }
            else
            {
                Cache* lastnode = tail->pre;
                tail->pre = lastnode->pre;
                lastnode->pre->next = tail;
                hashmap.erase(lastnode->key);
                delete lastnode;
                //lastnode = nullptr;
                head->next->pre = curnode;
                curnode->next = head->next;
                curnode->pre = head;
                head->next = curnode;
                hashmap[key] = curnode;
            }
        }
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

