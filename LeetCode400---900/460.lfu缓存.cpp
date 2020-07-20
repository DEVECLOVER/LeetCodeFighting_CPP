/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 */

// @lc code=start
class LFUCache {
public:
//在LRU中，自己手写了双向链表，有人说要尽量使用系统自带的链表，那就在这里用吧。
//从LRU到LFU，很有意思的。
//这个代码是带着很大的情绪写的，很不开心。再加上电脑的令人烦躁而怒火中烧的风扇声音，
//有几次想要将电脑砸掉，很生气
    struct Node
    {
        public:
            int key;
            int val;
            int freq;
            Node* pre;
            Node* next;
            Node(int _key,int _val,int _freq):key(_key),val(_val),freq(_freq),pre(nullptr),next(nullptr)
            {

            }
    };
    struct DbList
    {
        public:
            Node* head;
            Node* tail;
            int size = 0;
            DbList()
            {
                head = new Node(-1,-1,0);
                tail = new Node(-1,-1,0);
                tail->pre = head;
                head->next = tail;
                size = 0;
            }
            void push_front(Node* newnode)
            {
                head->next->pre = newnode;
                newnode->next = head->next;
                newnode->pre = head;
                head->next = newnode;
                ++size;
            }
            void Erase(Node* newnode)
            {
                --size;
                newnode->next->pre = newnode->pre;
                newnode->pre->next = newnode->next;
                return;
            }
            Node* Pop_tail()
            {
                auto curnode = tail->pre;
                Erase(curnode);
                return curnode;
            }
    };
    int cap;
    map<int,Node*> keymap;
    map<int,DbList> freqmap;
    void GetMore(Node* curnode)
    {
        freqmap[curnode->freq].Erase(curnode);
        if(freqmap[curnode->freq].size == 0)
            freqmap.erase(curnode->freq);
        freqmap[++curnode->freq].push_front(curnode);
    }
    void Add(Node* curnode)
    {
        keymap[curnode->key] = curnode;
        freqmap[curnode->freq].push_front(curnode);
    }
    void Pop()
    {
        if(freqmap.empty())
            return;
        auto it = freqmap.begin();
        auto node = it->second.Pop_tail();
        if(it->second.size == 0)
            freqmap.erase(it);
        keymap.erase(node->key);
    }


    // int cap;
    // int minfreq;
    // map<int,list<Node*>> freqmap;
    // map<int,Node*> keymap;
    LFUCache(int capacity) {
        // minfreq = 0;
        // cap = capacity;
        cap = capacity;

    }
    
    int get(int key) {
        // if(cap == 0 || !keymap.count(key))
        //     return -1;
        // auto curnode = keymap[key];
        // //不能这样删除
        // freqmap[curnode->freq].erase(curnode);  
        // if(freqmap[curnode->freq].size() == 0)
        // {
        //     freqmap.erase(curnode->freq);
        //     if(minfreq == curnode->freq)
        //         ++minfreq;
        // }
        // freqmap[curnode->freq + 1].push_front(new Node(key,curnode->val,curnode->freq + 1));
        // keymap[key] = freqmap[curnode->freq + 1].begin();
        // return curnode->val;
        if(cap == 0 || !keymap.count(key))
            return -1;
        auto node = keymap[key];
        GetMore(node);
        return node->val;


    }
    
    void put(int key, int value) {
        // if(cap == 0)
        //     return ;
        // if(keymap.count(key))
        // {
        //     auto curnode = keymap[key];
        //     freqmap[curnode->freq].erase(curnode);
        //     if(freqmap[curnode->freq].size() == 0)
        //     {
        //         freqmap.erase(curnode->freq);
        //         if(minfreq == curnode->freq)
        //             ++minfreq; 
        //     }
        //     freqmap[curnode->freq + 1].push_front(new Node(key,value,curnode->freq + 1));
        //     keymap[key] = freqmap[curnode->freq + 1].begin();
        // }
        // else
        // {
        //     if(keymap.size() == cap)
        //     {
        //         auto lastnode = freqmap[minfreq].back();
        //         keymap.erase(lastnode->key);
        //         freqmap[minfreq].pop_back();
        //         if(freqmap[minfreq].size() == 0)
        //         {
        //             freqmap.erase(minfreq);
        //         }
        //     }
        //     freqmap[1].push_front(new Node(key,value,1));
        //     keymap[key] = freqmap[1].begin();
        //     minfreq = 1;
        // }
        if(cap == 0) 
            return;
        if(!keymap.count(key))
        {
            if(keymap.size() == cap)
                Pop();
            Add(new Node(key,value,1));
        }
        else
        {
            auto node = keymap[key];
            node->val = value;
            GetMore(node);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

