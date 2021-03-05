#include "mms.h"

// TODO: New and assign test
// TODO: Assign heap to other empty heap test
// TODO: Assign heap to other assigned heap test 
// TODO: ^ Assigned heap will be free case
// TODO: Parameter test
// TODO: Return heap test
// TODO: Return heap but not catch test (will be free case)
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