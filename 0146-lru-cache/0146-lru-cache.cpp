class LRUCache {
public:
    class node{
        public:
            int key;int val;
            node *next, *prev;
            node(int _k, int _v){
                key = _k; val = _v;
            }
    };
    unordered_map<int, node*> mp;
    int capacity;

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* nd){
        node* temp = head->next;
        nd->next = temp;
        nd->prev = head;
        temp -> prev = nd;
        head -> next = nd;
        
    }

    void deletenode(node* nd){
        node* next = nd->next;
        node* prev = nd->prev;

        prev->next = next;
        next->prev = prev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* nd = mp[key];
            int val = nd->val;

            mp.erase(key);
            deletenode(nd);
            addnode(nd);

            mp[key] = head->next;

            return val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* nd = mp[key];
            mp.erase(nd->key);
            deletenode(nd);
        }
        if(mp.size() == capacity){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */