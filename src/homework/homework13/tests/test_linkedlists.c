#include "utest.h"
#include "linkedlists.h"

static void dummy_op(Data* d) {
}

UTEST(linked_list_traverse, null_list) {
    linked_list_traverse(NULL, dummy_op);
    ASSERT_TRUE(1);
}

UTEST(linked_list_traverse, null_operator) {
    LinkedList* list = linked_list_create();

    linked_list_traverse(list, NULL);

    linked_list_free(&list);
    ASSERT_TRUE(1);
}

UTEST_MAIN()
