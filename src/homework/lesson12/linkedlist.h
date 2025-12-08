#pragma once
// ifndef LINKEDLIST_H

typedef struct {
    int element;
} Value;

struct Node;

struct Node{
    Value value;
    struct Node *next;
};

typedef struct Node node;

// or we can write it like this:
// typedef struct Node{
//     Value value;
//     Node *next;
// }Node;

typedef struct {
    struct Node *head;

} LinkedList;
/** 
 * @brief Create a new empty linked list
 * @return A pointer to the newly created list
 */
LinkedList *linked_list_create();

/**
 * @brief Insert a new value after previous
 * @param list The Linked List
 * @param previous The new node will be inserted after this one.
 * If NULL, the new node will be inserted at the head of the list
 * @param value The value to put into the new node
 * @return 0 if successful, -1 for errors
 */
int linked_list_insert(LinkedList *list, node *previous, Value value);

// #endif // LINKEDLIST_H