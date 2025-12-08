#include <stdlib.h>
#include "linkedlists.h"

void linked_list_traverse(LinkedList* list, void (*op)(Data*)) {
    if (!list || !op) {
        return;
    }

    Node* current = list->head;
    while (current) {
        op(&current->data);
        current = current->next; 
    }
}

