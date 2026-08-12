class Node{
public:
    int val;
    Node* next ;
    Node* prev;
    Node(int x)
    {
        val = x;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
   
public:
    unordered_map<int , pair<int , Node*>>m;

    int size ;
    int siz = 0;

    Node*head = nullptr;
    Node*tail = nullptr;

    LRUCache(int capacity) {
        size = capacity;
    }
    void move_to_head(Node* node)
    {
        if(node == head) return ;

        // detach node;
        if(node->prev)
        node->prev->next = node->next;

        if(node->next)
        node->next->prev = node->prev;

        if(node == tail)
        tail = tail->prev;

        // move to head
        node->next = head;
        node->prev = nullptr;

        if(head)
        head->prev = node;

        head = node;
        
        if(tail == nullptr)
         tail = head;
    }
    int get(int key) {
        //work -> if present then find it and update to linkedlist else return -1
        if(m.count(key))
        {
         move_to_head(m[key].second);

        return m[key].first;

        }
        else 
        return -1;
    }
    
    void put(int key, int value) {

        
      if(m.count(key))
      {
        move_to_head(m[key].second);

        //set value
        m[key] = {value , head};

        return ;
      }
      if(siz == size)
        {
            //work->erease key from map , update tail pointe , update size;

            m.erase(tail->val);

            Node* temp = tail;

            tail = tail->prev;
            if(tail)
            tail->next = nullptr;
            else
            head = nullptr;
            
            delete temp;

            siz--;
        }
        //work->create a node move it to head , and store its data in map

        Node* temp = new Node(key);
        temp->prev = nullptr;
        temp->next = head;
        
        if(head)
        head->prev = temp;

        head = temp;
        
        if(tail == nullptr) 
        tail = temp;

        //store data in map
        m[key] = {value , head};

        //increse size;
        siz++;

      
    }
};
