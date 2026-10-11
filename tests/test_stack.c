/* test_stack.c - Unit tests for the array stack. Run with: make test */
#include <assert.h>
#include <stdio.h>

#include "../src/stack.h"

int main(void) {
    Stack s;
    int v = 0;
    stack_init(&s);

    /* Empty stack. */
    assert(stack_is_empty(&s));
    assert(stack_size(&s) == 0);
    assert(stack_pop(&s, &v) == STACK_UNDERFLOW);
    assert(stack_peek(&s, &v) == STACK_UNDERFLOW);

    /* LIFO order. */
    assert(stack_push(&s, 1) == STACK_OK);
    assert(stack_push(&s, 2) == STACK_OK);
    assert(stack_push(&s, 3) == STACK_OK);
    assert(stack_size(&s) == 3);
    assert(stack_peek(&s, &v) == STACK_OK && v == 3);
    assert(stack_size(&s) == 3);  /* peek must not remove */
    assert(stack_pop(&s, &v) == STACK_OK && v == 3);
    assert(stack_pop(&s, &v) == STACK_OK && v == 2);
    assert(stack_pop(&s, NULL) == STACK_OK);  /* discard */
    assert(stack_is_empty(&s));

    /* Fill to capacity, then overflow. */
    for (int i = 0; i < STACK_MAX; ++i) assert(stack_push(&s, i) == STACK_OK);
    assert(stack_is_full(&s));
    assert(stack_push(&s, 999) == STACK_OVERFLOW);
    assert(stack_peek(&s, &v) == STACK_OK && v == STACK_MAX - 1);

    printf("All tests passed\n");
    return 0;
}
