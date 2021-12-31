#include "mms.h"

// Create new heap filled with 0
Heap *new_heap() {
    Heap *heap = calloc(1, sizeof(Heap));
    // Initialize
    heap->refc = 0;
    heap->data = 0;
    heap->heap = NULL;
    return heap;
}

// New assign function
void assign(Heap **to, Heap *ref) {
    ref->refc++;
    if (*to) {
        free_heap(*to);
    }
    *to = ref;
}

// Releas heap memory if its reference is 0 (Need to call end of function)
void free_heap(Heap *heap) {
    heap->refc--;
    if (heap->refc <= 0) {
        if (heap->heap) {
            free_heap(heap->heap);
        }
        printf("Free\n");
        free(heap);
        heap = NULL;
    }
}
