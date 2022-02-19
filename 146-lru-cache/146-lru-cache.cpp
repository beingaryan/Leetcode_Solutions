class LRUCache {
public:
    
    class node{
        public:
        int key;
        int val;
        node*next;
        node*prev;
        
        node(int key,int val){
            this->key=key;
            this->val=val;
            
        }
        
    };
    int  cap;
    unordered_map<int,node*>mp;
    node* head=new node(-1,-1);
    node*tail=new node(-1,-1);
    
    LRUCache(int capacity) {
        this->cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    //H F T
    void addNode(node* newNode){
        node* nextNode=head->next;
        newNode->next=nextNode;
        head->next=newNode;
        newNode->prev=head;
        newNode->next->prev=newNode;
        
    }
    
    void deleteNode(node* newNode){
        node*deleteNext=newNode->next;
        node* deletePrev=newNode->prev;
        deletePrev->next=deleteNext;
        deleteNext->prev=deletePrev;
    }
    
    int get(int key) {
       if(mp.find(key)!=mp.end()){
           node* toCheck=mp[key];
           int res=toCheck->val;
           mp.erase(key);
           deleteNode(toCheck);
           addNode(toCheck);
           mp[key]=head->next;
           return res;
       }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* toCheck=mp[key];
            mp.erase(key);
            deleteNode(toCheck);
            
        }
        
        if(mp.size()>=cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
            
        }
        
        addNode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */