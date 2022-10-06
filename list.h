
class Node {
    friend void *print(Node *h);
    friend class List;
    int data;
    Node *next;
public:
    Node(int d) :data{d}, next{nullptr} {}
    ~Node() { 
        if (next != nullptr) {
            delete next;
        }
        std::cout << "deleting node, data " << data << "\n";
    }
    int getData() { return data; }
};

class List {
    Node *head;
    Node *tail;
    
    int searchHelper(Node *h, int k) {
        // base case
        if (h == nullptr)
            return -1;
        // value matches
        if (h->data == k)
            return 0;
            
        int subIdx = searchHelper(h->next,k);
        if (subIdx == -1)
            return -1;
        return subIdx + 1;
    }
    
public:
    List() :head{nullptr}, tail{nullptr} {}
    ~List() {
        if (head != nullptr) {
            delete head;
            head = nullptr;
        }
    }
    
    Node *begin() { return head; }
    Node *end() { return tail; }
    
    void push_front(int d) {
        if (head == nullptr) {
            Node *n = new Node(d);
            head = tail = n;
            return;
        }
        Node *n = new Node(d);
        n->next = head;
        head = n;
    }
    
    void push_back(int d) {
        if (head == nullptr) {
            Node *n = new Node(d);
            head = tail = n;
            return;
        }
        Node *n = new Node(d);
        tail->next = n;
        tail = n;
    }
    
    void insert(int d, int in) {
        if (head == nullptr) {
            Node *n = new Node(d);
            head = tail = n;
            return;
        }
        
        if (in == 0) {
            push_front(d);
            return;
        }
        
        Node *temp = head;
        for (int i = 1; i < in; i++) {
            temp = temp->next;
        }
        Node *n = new Node(d);
        
        n->next = temp->next;
        temp->next = n;
    }
    
    int search(int k){
 
		Node * temp = head;
		int idx = 0;
 
		while(temp!=nullptr){
			if(temp->data == k){
				return idx;
			}
			idx++;
			temp = temp->next;
		}	
		return -1;
	}
    
    int recursiveSearch(int k) {
        int idx = searchHelper(head,k);
        return idx;
    }
    
    void pop_front() {
        if (head == nullptr) {
            std::cout << "head is null\n";
            return;
        }
        
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    
    void pop_back() {
        if (head == nullptr) {
            std::cout << "head is null\n";
            return;
        }
        
        // find new_tail
        Node *new_tail;
        Node *list_it = head;
        
        while (list_it != tail) {
            new_tail = list_it;
            list_it = list_it->next;
        }
        
        // pop_back()
        Node *temp = tail;
        tail = new_tail;
        new_tail->next = nullptr;
        delete temp;
    }
    
    void remove(int it) {
        if (head == nullptr) {
            std::cout << "head is null\n";
            return;
        }
        
        Node *list_it = head;
        
        for (int i = 0; i < it-1; i++) {
            list_it = list_it->next;
        }
        
        Node *temp = list_it->next;
        list_it->next = list_it->next->next; 
        temp->next = nullptr;
        delete temp;
    }
    
    void reverse() {
        if (head == nullptr) {
            std::cout << "head is null\n";
            return;
        }
        
        Node *c = head;
        Node *p = nullptr;
        Node *n;
        
        while (c != nullptr) {
            // save the next node
            n = c->next;
            // make the current node point to prev
            c->next = p;
            
            // update p and c take them 1 step forward
            p = c;
            c = n;
        }
        head = p;
        
    }
    
    void print() {
        if (head == nullptr) {
            std::cout << "head is null\n";
            return;
        }
        Node *n = head;
        while(n != nullptr) {
            std::cout << n->data << "->";
            n = n->next;
        }
        std::cout << "null\n";
    }
    
};
