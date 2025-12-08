#include "linkedlist.h"
#include <stdlib.h>

LinkedList *linked_list_create()
{
    LinkedList *list;
    list = malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

