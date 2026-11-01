class LRUCache {
public:
    class node{
        public:
        int key,value;
        node* next;
        node* prev;

        node(int k,int v)
        {
            key=k;
            value=v;

            prev=NULL;
            next=NULL;
        }
    };

    int capacity;
    unordered_map<int,node*> mpp;

    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    //remove tthe node
    void deleteNode(node* temp)
    {
        node* after= temp->next;
        node* before= temp->prev;

        before->next=after;
        after->prev=before;
    }

    //insert node after head
    void insertNode(node* temp)
    {
        node* after = head->next;

        head->next=temp;
        temp->prev=head;

        temp->next=after;
        after->prev=temp;
    }

    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {

        //first check if the node exist
        if(mpp.find(key)==mpp.end())
            return -1;
        
        //if exist
        node* temp= mpp[key];
        deleteNode(temp);
        insertNode(temp);

        return temp->value;   
    }
    
    void put(int key, int value) {

        //check if already exists
        if(mpp.find(key)!=mpp.end())
        {
            node* temp=mpp[key];
            temp->value=value;

            deleteNode(temp);
            insertNode(temp);

            return ;
        }
        //if node exist
        //first check the capacity
        if(mpp.size()==capacity)
        {
            node* temp=tail->prev;
            mpp.erase(temp->key);

            deleteNode(temp);
           
            delete temp;
        }
        node* n=new node(key,value);
        mpp[key]=n;
        insertNode(n);   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
