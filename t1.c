#include "mms.h"

void parameter_test(Heap **heap) {
    // Parameter assign process
    (*heap)->refc++;
    (*heap)->data = 20;
    // Destroy process
    free_heap(heap);
}

Heap** return_heap_test() {
    Heap *rheap = NULL;
    Heap **heap = &rheap;
    assign(heap, new_heap());
    (*heap)->data = 100;
    // Only sub heap "refc" not free when returning heap.
    // But if the returned routine doesn't catch the value, it must be free.
    // free_heapを実行するかrefc--を実行するかはコンパイラが判断する
    (*heap)->refc--;
    // =========================================================
    return heap;
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

    printf("Parameter test\n");
    parameter_test(heap);

    printf("Data: %d\n", (*heap)->data);
    printf("Data: %d\n", (*para)->data);

    printf("Return heap test\n");
    assign(heap, return_heap_test());
    printf("Data: %d\n", (*heap)->data);

    printf("Return heap but not catch test\n");
    // Freeを入れるかどうかはコンパイラが判断を行う
    free(*(return_heap_test()));
    printf("Free\n");
    // ========================================

    // printf("Heap's heap test\n");
    // assign((*heap)->heap, new_heap());
    // (*((*heap)->heap))->data = 201;
    // printf("Data: %d\n", (*((*heap)->heap))->data);
    // TODO: other case

    // Destroy process
    // If there are more heaps in the heap, you must also run free_heap on that heap.
    free_heap(heap);
    free_heap(para);
}

