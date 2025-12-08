#include <stdlib.h>
#include "linkedlists.h"

void linked_list_traverse(LinkedList* list, LinkedListOp op) {
    if (!list || !op) {
        return;
    }

    Node* current = list->head;
    while (current) {
        op(&current->data);
        current = current->next; 
    }
}

