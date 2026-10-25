class LRUCache {
public:
    class Node{
        public:
        int val;
        Node *prev,*next;

        Node(int data){
            val = data;
            prev=NULL;
            next=NULL;
        }
    };

    int size;
    map<int,Node*>mp;//key ->root
    map<Node*,int>mp2;//root->key

    Node *head,*tail;

    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1);
        tail = new Node(-1);
        head->next =tail;
        tail->prev = head;
    }

    void deletion(Node *root){
        root->prev->next=root->next;
        root->next->prev=root->prev;
        root->next=NULL;
        root->prev=NULL;
        int key = mp2[root];
        mp2.erase(root);
        mp.erase(key);
    }

    void insertion(int key, int val){
        Node* root= new Node(val);
        root->next = head->next;
        root->prev = head;
        head->next->prev=root;
        head->next=root;
        mp2[root] =key;
        mp[key] = root;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }

        Node *root = mp[key];
        deletion(root);
        insertion(key,root->val);

        return root->val;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)==mp.end()){
            if(size==0){
                deletion(tail->prev);
                size++;
            }
            insertion(key,value);
            size--;
        }
        else{
            Node *root = mp[key];
            deletion(root);
            insertion(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */