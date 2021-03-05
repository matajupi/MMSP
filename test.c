#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <CUnit/TestDB.h>
#include "mms.h"
#include <string.h> // keshi

void Test_CreateAndAssign(void);
void Test_AssignToAnotherEmpty(void);
void Test_AssignToAnotherAssigned_NormalCase(void);
void Test_AssignToAnotherAssigned_FreeCase(void);
void Test_PassAsArgument(void);
void Test_Return_GetCase(void);
void Test_Return_LostCase(void);
void Test_Inner(void);

int main(void) {
    CU_pSuite suite;
    CU_initialize_registry();

    suite = CU_add_suite("MMS Test", NULL, NULL);
    CU_add_test(suite, "Test_CreateHeapAndAssign", Test_CreateAndAssign);
    CU_add_test(suite, "Test_AssignToAnotherEmpty", Test_AssignToAnotherEmpty);
    CU_add_test(suite, "Test_AssignToAnotherAssigned_NormalCase", Test_AssignToAnotherAssigned_NormalCase);
    CU_add_test(suite, "Test_AssignToAnotherAssigned_FreeCase", Test_AssignToAnotherAssigned_FreeCase);
    CU_add_test(suite, "Test_PassAsArgument", Test_PassAsArgument);
    CU_add_test(suite, "Test_Return_GetCase", Test_Return_GetCase);
    CU_add_test(suite, "Test_Return_LostCase", Test_Return_LostCase);
    CU_add_test(suite, "Test_Inner", Test_Inner);

    CU_console_run_tests();
    CU_cleanup_registry();
    return 0;
}

void Test_CreateAndAssign(void) {
    Heap *heap = NULL;
    assign(&heap, new_heap());
    CU_ASSERT_EQUAL(1, heap->refc);
    free_heap(heap);
    return;
}

void Test_AssignToAnotherEmpty(void) {
    Heap *heap = NULL;
    assign(&heap, new_heap());
    heap->data = 10;
    Heap *another = NULL;
    assign(&another, heap);

    CU_ASSERT_EQUAL(heap, another);
    CU_ASSERT_EQUAL(10, heap->data);
    CU_ASSERT_EQUAL(2, heap->refc);

    free_heap(heap);
    free_heap(another);
    return;
}

void Test_AssignToAnotherAssigned_NormalCase(void) {
    Heap *heap = NULL;
    assign(&heap, new_heap());
    Heap *heap2 = NULL;
    assign(&heap2, new_heap());
    Heap *another = NULL;
    assign(&another, heap2);

    assign(&another, heap);

    CU_ASSERT_EQUAL(heap, another);
    CU_ASSERT_NOT_EQUAL(heap2, another);

    free_heap(heap);
    free_heap(heap2);
    free_heap(another);
}

void Test_AssignToAnotherAssigned_FreeCase(void) {
    Heap *heap = NULL;
    assign(&heap, new_heap());
    heap->data = 1;
    Heap *tmp = heap;
    Heap *heap2 = NULL;
    assign(&heap2, new_heap());
    heap2->data = 2;

    assign(&heap, heap2);

    CU_ASSERT_EQUAL(heap, heap2);
    CU_ASSERT_EQUAL(2, heap->data);
    CU_ASSERT_NOT_EQUAL(tmp, heap);

    free_heap(heap);
    free_heap(heap2);
}

void arg_test(Heap *argh) {
    Heap *heap = NULL;
    assign(&heap, argh);
    heap->data = 10;
    free_heap(heap);
    return;
}

void Test_PassAsArgument(void) {
    Heap *heap = NULL;
    assign(&heap, new_heap());
    heap->data = 3;
    arg_test(heap);

    CU_ASSERT_EQUAL(10, heap->data);

    free_heap(heap);
}

Heap* retget_test() {
    Heap *heap = NULL;
    assign(&heap, new_heap());
    heap->data = 4;
    return heap;
}

void Test_Return_GetCase(void) {
    Heap *heap = NULL;
    // tmpは戻り値を暗黙のうちに受け取る
    Heap *tmp = retget_test();
    assign(&heap, tmp);
    free_heap(tmp);
    
    CU_ASSERT_EQUAL(4, heap->data);

    free_heap(heap);
}

void Test_Return_LostCase(void) {
    Heap *heap = NULL;
    Heap *tmp = retget_test();
    free_heap(tmp);

    CU_ASSERT_EQUAL(NULL, heap);
}

void Test_Inner(void) {
    Heap *heap = NULL;
    assign(&heap, new_heap());
    assign(&(heap->heap), new_heap());

    heap->heap->data = 4;

    assign(&heap, (heap->heap));

    CU_ASSERT_EQUAL(4, heap->data);

    free_heap(heap);
}