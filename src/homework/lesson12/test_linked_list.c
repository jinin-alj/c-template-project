#include "utest.h"
#include <assert.h>
#include "linkedlist.h"

UTEST(LinkedList, creation){
    LinkedList *list = linked_list_create();
    assert(list != NULL);
}
UTEST(LinkedList, insert_at_head){
    LinkedList *list = linked_list_create();
    Value val;
    val.element = 1;
    int error = linked_list_insert(list, NULL, val);
    assert(list->head->value.element == val.element);
    assert(error == 0);
}
UTEST(LinkedList, insert_not_at_head){
    LinkedList *list = linked_list_create();
    Value val;
    val.element = 1;
    int error = linked_list_insert(list, NULL, val);
    val.element = 2;
    error = linked_list_insert(list, list->head, val);
    assert(list->head->next->value.element == val.element);
    assert(error == 0);
}
UTEST_MAIN();