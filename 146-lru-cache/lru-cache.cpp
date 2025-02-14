class Node {
public:
    int key;
    int value;
    Node* left;
    Node* right;

    Node(int k,int v){
        key = k;
        value = v;
        left = NULL;
        right = NULL;
    }
};

class LRUCache {
public: 
    Node* L; //LRU
    Node* R; //MRU
    int cap;

    unordered_map<int,Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        L = new Node(0,0);
        R = new Node(0,0);

        L->right = R;
        R->left = L;
    }

    void remove(Node* node){
        node->left->right = node->right;
        node->right->left = node->left;

        mp.erase(node->key);

        return;
    }

    void insert(Node* node){
        node->left = R->left;
        node->right = R;
        node->left->right = node;
        R->left = node;

        mp[node->key] = node;

        return;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            auto node = mp[key];
            remove(node);
            insert(node);
            return node->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto node = mp[key];
            remove(node);
        }

        Node* node = new Node(key,value);
        insert(node);

        if (mp.size() > cap) remove(L->right);

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */