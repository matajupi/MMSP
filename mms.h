#include <stdio.h>
#include <stdlib.h>

typedef struct Heap Heap;

struct Heap {
    int data;
    int refc;
};

Heap **new_heap();
void assign(Heap **to, Heap **from);
void free_heap(Heap **heap);