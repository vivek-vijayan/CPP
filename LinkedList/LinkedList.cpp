#include "iostream"

class Node
{
public:
    int data;
    Node *next;
};

void printList(Node *n){
    while(n!=NULL) {
        std::cout << n->data << std::endl;
        n = n->next;
    };
}

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->next = second; 
    head->data = 1;

    second->next = third;
    second->data = 2;

    third->next = NULL;
    third->data = 3;

    printList(head);
}