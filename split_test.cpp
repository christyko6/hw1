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
    first = NULL;
    printLL(first);
    //std::cout<<"hi"<<std::endl;

    // Node* head = NULL;
    // Node* second = NULL;
    // Node* third = NULL;

    // head = new Node();
    // second = new Node();
    // head -> value = 1;
    // head -> next = second;
    // second -> value = 2;
    // second ->next = third;
    // third -> value = 3;
    // third->next = NULL;
    


    return 0;
}