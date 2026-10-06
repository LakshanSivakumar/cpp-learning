#include <cstddef>
#include <iostream>

struct Node {
    int value;
    Node* next;
};

int main(void){
    Node c {3, nullptr};
    Node b{2, &c};
    Node a{1, &c};
    Node *head = &a;

    for (Node *p = head; p != nullptr; p = p->next){
        std::cout << p->value << ' ';
    }
    std::cout << '\n';
    return 0;
}