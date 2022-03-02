class LRUCache {
public:
    const int nax = 1e4 + 1;
    int cap;
    int size = 0;
    struct ListNode {
        pair<int, int> val;
        ListNode* prev;
        ListNode* next;
        ListNode(pair<int, int> a) {
            val = a;
            prev = nullptr;
            next = nullptr;
        }
    };
    vector<ListNode*> ptr;
    ListNode* head;
    ListNode* foot;
    ListNode* insert(pair<int, int> v) {
        if (head == nullptr && foot == nullptr) {
            head = new ListNode(v);
            foot = head;
            ++size;
            return head;
        }
        ListNode* temp = new ListNode(v);
        temp->prev = foot;
        foot->next = temp;
        foot = temp;
        ++size;
        return foot;
    }
    void removeLeast() {
        if (head->prev == nullptr && head->next == nullptr) {
            auto [k, v] = head->val;
            delete head;
            head = nullptr;
            foot = nullptr;
            ptr[k] = nullptr;
            --size;
            return;
        }
        ListNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        --size;
        ptr[temp->val.first] = nullptr;
        delete temp;
    }
    void remove(ListNode* node) {
        if (node->prev == nullptr && node->next == nullptr) {
            delete node;
            head = nullptr;
            foot = nullptr;
            --size;
            return;
        }
        if (node->prev == nullptr) {
            head = node->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete node;
            --size;
            return;
        }
        if (node->next == nullptr) {
            ListNode* temp = node->prev;
            temp->next = nullptr;
            foot = temp;
            delete node;
            --size;
            return;
        }
        ListNode* temp = node->prev;
        temp->next = node->next;
        node->next->prev = temp;
        --size;
        delete node;
    }
    LRUCache(int capacity) {
        cap = capacity;
        ptr = vector<ListNode*> (nax, nullptr);
        head = nullptr;
        foot = nullptr;
    }
    
    int get(int key) {
        if (ptr[key] == nullptr) return -1;
        pair<int, int> p = ptr[key]->val;
        remove(ptr[key]);
        ptr[key] = insert(p);
        
        return p.second;
    }
    
    void put(int key, int value) {
        if (ptr[key] == nullptr && size == cap) {
            removeLeast();
            ptr[key] = insert(make_pair(key, value));
            
            return;
        }
        if (ptr[key] != nullptr) {
            pair<int, int> p = ptr[key]->val;
            p.second = value;
            remove(ptr[key]);
            ptr[key] = insert(p);
            return;
        }
        ptr[key] = insert(make_pair(key, value));
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */