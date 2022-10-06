#include <iostream>
#include "list.h"

void print(Node *h) {
    if (h == nullptr) {
            std::cout << "head is null\n";
            return;
        }
        Node *n = h;
        while(n != nullptr) {
            std::cout << n->data << "->";
            n = n->next;
        }
        std::cout << "null\n";
}

std::ostream &operator<<(std::ostream &os, Node *h) {
    print(h);
    return os;
}

int main(){
    List *l = new List{};
    
    for (unsigned i = 0; i < 10; i++)
        l->push_back(i);
    
    l->print();
    
    l->pop_back();
    
    l->print();
    
    l->remove(5);
    
    l->print();
    
    l->reverse();
    l->print();
    delete l;
    
    List *l2 = new List{};
    
    l2->insert(3,5);
    //l2->insert(3,2);
    for (unsigned i = 0; i < 5; i++)
        l2->push_back(5);
        
    std::cout << l2->begin();
    std::cout << "\n\n\n";
    delete l2;
    
    return 0;
}
