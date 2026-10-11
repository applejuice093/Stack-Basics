/* stack.h - Fixed-capacity stack of ints backed by an array.
 *
 * All operations are O(1). Functions that can fail return a StackStatus
 * instead of printing, so callers decide how to handle errors.
 */
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

#define STACK_MAX 100  /* capacity of every stack */

typedef struct {
    int items[STACK_MAX];
    int top;           /* index of the top element, -1 when empty */
} Stack;

typedef enum {
    STACK_OK = 0,
    STACK_OVERFLOW,    /* push on a full stack */
    STACK_UNDERFLOW    /* pop/peek on an empty stack */
} StackStatus;

void        stack_init(Stack *s);
bool        stack_is_empty(const Stack *s);
bool        stack_is_full(const Stack *s);
size_t      stack_size(const Stack *s);
StackStatus stack_push(Stack *s, int value);
StackStatus stack_pop(Stack *s, int *out);
StackStatus stack_peek(const Stack *s, int *out);

#endif
