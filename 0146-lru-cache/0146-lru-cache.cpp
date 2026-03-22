class LRUCache {
public:
    struct ListNode{
        int key, val;
        ListNode *prev, *next;

        ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    ListNode *head, *tail;
    unordered_map<int, ListNode*> cache;
    int capacity;

    void insertAtHead(ListNode *node){
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }

    void removeNode(ListNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        removeNode(cache[key]);
        insertAtHead(cache[key]);

        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()){
            ListNode *newNode = new ListNode(key, value);
            cache[key] = newNode;
            insertAtHead(newNode);
        }
        else {
            ListNode *node = cache[key];
            node->val = value;
            removeNode(node);
            insertAtHead(node);
        }

        if (cache.size() > capacity){
            ListNode *LRU = tail->prev;
            cache.erase(LRU->key);
            removeNode(LRU);
            delete LRU;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */