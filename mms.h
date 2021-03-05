#include <stdio.h>
#include <stdlib.h>

typedef struct Heap Heap;

struct Heap {
    int refc;
    int data;
    Heap *heap;
};

Heap *new_heap();
void assign(Heap **to, Heap *ref);
void free_heap(Heap *heap);