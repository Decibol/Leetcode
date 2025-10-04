class LRUCache {
private:
    struct ListNode{
        int key, val;
        ListNode *prev;
        ListNode *next;

        ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    ListNode *head, *tail;
    unordered_map<int, ListNode*> cache;
    int capacity;

    void removeNode(ListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(ListNode* node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        ListNode *node = cache[key];
        removeNode(node);
        insertAtHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){
            ListNode *node = cache[key];
            node->val = value;
            removeNode(node);
            insertAtHead(node);
        }
        else {
            if (cache.size() == capacity){
                ListNode *lru = tail->prev;
                cache.erase(lru->key);
                removeNode(lru);
                delete lru;
            }

            ListNode *newNode = new ListNode(key, value);
            cache[key] = newNode;
            insertAtHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */