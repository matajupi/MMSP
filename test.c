#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <CUnit/TestDB.h>
#include "mms.h"
#include <string.h> // keshi

void Test_CreateAndAssign(void);
void Test_AssignToAnotherEmpty(void);
void Test_AssignToAnotherAssigned_NormalCase(void);

int main(void) {
    CU_pSuite suite;
    CU_initialize_registry();

    suite = CU_add_suite("MMS Test", NULL, NULL);
    CU_add_test(suite, "Test_CreateHeapAndAssign", Test_CreateAndAssign);
    CU_add_test(suite, "Test_AssignToAnotherEmpty", Test_AssignToAnotherEmpty);
    CU_add_test(suite, "Test_AssignToAnotherAssigned_NormalCase", Test_AssignToAnotherAssigned_NormalCase);

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