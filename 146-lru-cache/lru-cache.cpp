class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key,int val){
        this->key = key;
        this->val = val;
    }
};


class LRUCache {
    int cap;
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> mp;

    
void insertNode(Node* node){
        Node* temp = head->next;
        node->prev = head;
        node->next = temp;
        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node* node){
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    LRUCache(int capacity) {
        this->cap  = capacity;
        head->next = tail;
        tail->prev = head;
    }

    
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            int value = node->val;
            mp.erase(key);
            deleteNode(node);
            insertNode(node);

            mp[key] = node;
            return value;
        }else return -1;
       
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            mp.erase(key);
            deleteNode(node);
        }    

        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }  

        insertNode(new Node(key,value));
        mp[key] = head->next;  
    }
};

