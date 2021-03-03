#include "mms.h"

// Create new heap filled with 0
Heap **new_heap() {
    Heap *rheap = calloc(1, sizeof(Heap));
    Heap **heap = &rheap;
    (*heap)->data = 0;
    (*heap)->refc = 0;
    return heap;
}

// "to" = "from"
void assign(Heap **to, Heap **from) {
    if (*to) {
        free_heap(to);
    }
    *to = *from;
    (*to)->refc++;
}

// Releas heap memory if its reference is 0 (Need to call end of function)
void free_heap(Heap **heap) {
    (*heap)->refc--;
    if ((*heap)->refc <= 0) {
        printf("Free\n");
        free(*heap);
    }
}