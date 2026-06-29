#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"

Node* create_node(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert_tail(Node** head, int value) {
    Node* newNode = create_node(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int search_node(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) return 1;
        temp = temp->next;
    }
    return 0;
}