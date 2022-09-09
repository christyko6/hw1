#include "split.h"
#include <cstddef>
#include <iostream>

void printLL(Node* node){
    while(node != NULL){
        std::cout<<node->value<<" ";
        node = node->next;
    }
    std::cout<<std::endl;
}

int main(){
    Node* first = new Node(1, NULL);
    Node* second = new Node(2, NULL);
    Node* third = new Node(3, NULL);
    first->next = second;
    second->next = third;
    Node* evens = NULL;
    Node* odds = NULL;
    printLL(first);
    split(first, odds, evens);

    printLL(odds);
    printLL(evens);
    printLL(first);
    


    return 0;
}