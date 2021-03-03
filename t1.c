#include "mms.h"

void sub(Heap **heap) {
    // Parameter assign process
    (*heap)->refc++;
    (*heap)->data = 20;
    // Free
    free_heap(heap);
}

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

    // Heap *rnewheap = NULL;
    // Heap **newheap = &rnewheap;

    // assign(newheap, new_heap());

    // assign(heap, newheap);

    assign(heap, new_heap());

    (*heap)->data = 10;
    printf("Data: %d\n", (*heap)->data);
    printf("Data: %d\n", (*para)->data);

    assign(para, heap);

    printf("Data: %d\n", (*heap)->data);
    printf("Data: %d\n", (*para)->data);

    sub(heap);

    printf("Data: %d\n", (*heap)->data);
    printf("Data: %d\n", (*para)->data);

    // Free
    free_heap(heap);
    free_heap(para);
    // free_heap(newheap);
}

