#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int value);
void insert_tail(Node** head, int value);
int search_node(Node* head, int target);

#endif 
