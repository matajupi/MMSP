#include "mms.h"

// DONE: New and assign test
// DONE: Assign heap to other empty heap test
// DONE: Assign heap to other assigned heap test 
// DONE: ^ Assigned heap will be free case
// DONE: Parameter test
// DONE: Return heap test
// DONE: Return heap but not catch test (will be free case)
// TODO: Heap's heap(implement)
int main(int argc, char **argv) {
    Heap *heap = NULL;
    assign(&heap, new_heap());
    Heap *heap2 = NULL;
    assign(&heap2, new_heap());
    Heap *another = NULL;
    assign(&another, heap2);

    assign(&another, heap);

    free_heap(heap);
    free_heap(heap2);
    free_heap(another);
    return 0;
}