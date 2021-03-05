#include "mms.h"

// DONE: New and assign test
// DONE: Assign heap to other empty heap test
// DONE: Assign heap to other assigned heap test 
// DONE: ^ Assigned heap will be free case
// DONE: Parameter test
// DONE: Return heap test
// DONE: Return heap but not catch test (will be free case)
// DONE: Heap's heap(implement)
int main(int argc, char **argv) {
    Heap *a = NULL;
    assign(&a, new_heap());
    a->data = 10;
    Heap *b = NULL;
    assign(&b, new_heap());
    b->data = 5;
    Heap *c = NULL;
    assign(&c, new_heap());
    c->data = a->data + b->data;
    assign(&(c->heap), a);
    assign(&(a->heap), b);

    printf("C: %d\n", c->data);
    printf("A: %d\n", c->heap->data);
    printf("B: %d\n", c->heap->heap->data);

    free_heap(a);
    free_heap(b);
    free_heap(c);
    return 0;
}