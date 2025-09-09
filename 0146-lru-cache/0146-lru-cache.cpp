class LRUCache {
private:
    struct Node{
        int key, val;
        Node *prev, *next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;

    void removeNode(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node *node){
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        Node *node = cache[key];
        removeNode(node);
        insertAtHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.size() == capacity){
            Node *lru = tail->prev;
            removeNode(lru);
            cache.erase(lru->key);

            delete lru;
        }

        if (cache.find(key) != cache.end()){
            Node *node = cache[key];
            node->val = value;
            removeNode(node);
            insertAtHead(node);
        }
        else{
            Node *node = new Node(key, value);
            cache[key] = node;
            insertAtHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */