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
    if (*to) {
        free_heap(*to);
    }
    *to = ref;
    ref->refc++;
}

// Releas heap memory if its reference is 0 (Need to call end of function)
void free_heap(Heap *heap) {
    // TODO: If there is more heap in the heap, run free_heap on that heap as well.
    heap->refc--;
    if (heap->refc <= 0) {
        printf("Free\n");
        free(heap);
    }
}
