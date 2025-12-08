#pragma once
#include <stdlib.h>
#include <stdio.h>

    typedef struct{
        int value;
    } Data;


    typedef struct Node {
        Data data;
        struct Node* next;
    } Node;

    typedef struct {

        Node* head;

    } LinkedList;

    typedef void (*LinkedListOp)(Data*);

    LinkedList* linked_list_create() {
        LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
        list->head = NULL;
        return list;
    }

    int linked_list_insert(LinkedList* list, Node* prev_node, Data data) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        if (!new_node) {
            return -1;
        }
        new_node->data = data;
        Node* next = prev_node ? prev_node->next : list->head;
        new_node->next = next;
        if (prev_node) {
            prev_node->next = new_node;
        } else {
            list->head = new_node;
        }
        return 0;
    }

    void linked_list_print(LinkedList* list) {
        Node* current = list->head;
        while (current) {
            printf("%d -> ", current->data.value);
            current = current->next;
        }
        printf("NULL\n");
    }

    int linked_list_delete(LinkedList* list, Node* target) {
        if (!list->head || !target) {
            return -1; 
        }
        if (list->head == target) {
            list->head = target->next;
            free(target);
            return 0;
        }
        Node* current = list->head;
        while (current->next && current->next != target) {
            current = current->next;
        }
        if (!current->next) {
            return -1; 
        }
        current->next = target->next;
        free(target);
        return 0;
        }

    void linked_list_free(LinkedList** list) {
        if (!list || !*list) {
            return; 
        }
        Node* current = (*list)->head;
        while (current) {
            Node* next = current->next;
            free(current);
            current = next;
        }
        free(*list);
        *list = NULL;
    }

    void print_node(Data* data){
        if (data==NULL){
            printf("NULL\n");
            return;
        }
        printf("%d -> ", data->value);
    }
    void linked_list_traverse(LinkedList* list, LinkedListOp op);