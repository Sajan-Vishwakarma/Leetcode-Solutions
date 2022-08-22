class LRUCache {
public:
    class node{
        public:
        int key,val;
        node *next, *prev;
        node(int _k,int _v){
            key = _k; val = _v;
            next = prev = NULL;
        }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void insertAtbeg(node *temp){
        node *nextnode = head->next;
        temp->prev = head; head->next = temp;
        temp->next = nextnode; nextnode->prev = temp;
    }
    
    void deletenode(node *temp){
        node* prevnode = temp->prev, *nextnode = temp->next;
        prevnode->next = nextnode; // swapping pointers
        nextnode->prev = prevnode;
    }
    
    int get(int _key) {
        if( mp.find(_key) == mp.end()) 
            return -1;
        
        node *resnode = mp[_key];
        int res = resnode->val;
        mp.erase(_key);
        
        deletenode(resnode);    // swap pointer
        insertAtbeg(resnode);   // add node at from 
        mp[_key] = head->next;  // storing address
        
        return res;
    }
    
    void put(int _key, int _value) {
        if( mp.find( _key ) != mp.end() ){ // deltenode
            deletenode(mp[_key]);
            mp.erase(_key);
        }
        
        if( mp.size() == cap){
            mp.erase( tail->prev->key );
            deletenode( tail->prev );
        }
        
        insertAtbeg(new node(_key,_value));
        mp[_key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */