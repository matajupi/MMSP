#include "mms.h"

int main(int argc, char **argv) {
    // Definition
    Heap *rheap = NULL; // Reference
    Heap **heap = &rheap; // Stack address

    // Assign
    assign(heap, new_heap());

    // Process
    (*heap)->data = 3;
    printf("Data: %d\n", (*heap)->data);

    // Definition
    Heap *rpara = NULL;
    Heap **para = &rpara;

    // Assign
    assign(para, heap);

    // Process
    (*para)->data = 4;
    printf("Data: %d\n", (*heap)->data);
    printf("Data: %d\n", (*para)->data);

    // Free
    free_heap(heap);
    free_heap(para);
}

