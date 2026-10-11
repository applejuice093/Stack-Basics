/* stack.c - Array implementation of the Stack interface. */
#include "stack.h"

void stack_init(Stack *s) { s->top = -1; }

bool stack_is_empty(const Stack *s) { return s->top < 0; }

bool stack_is_full(const Stack *s) { return s->top >= STACK_MAX - 1; }

size_t stack_size(const Stack *s) { return (size_t)(s->top + 1); }

StackStatus stack_push(Stack *s, int value) {
    if (stack_is_full(s)) return STACK_OVERFLOW;
    s->items[++s->top] = value;
    return STACK_OK;
}

StackStatus stack_pop(Stack *s, int *out) {
    if (stack_is_empty(s)) return STACK_UNDERFLOW;
    int v = s->items[s->top--];
    if (out) *out = v;  /* out may be NULL to just discard the value */
    return STACK_OK;
}

StackStatus stack_peek(const Stack *s, int *out) {
    if (stack_is_empty(s)) return STACK_UNDERFLOW;
    if (out) *out = s->items[s->top];
    return STACK_OK;
}
