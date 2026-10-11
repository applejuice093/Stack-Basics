/* main.c - Interactive menu to try out the stack. */
#include <stdio.h>

#include "stack.h"

static void print_stack(const Stack *s) {
    if (stack_is_empty(s)) { printf("Stack is empty\n"); return; }
    printf("Stack (top -> bottom):");
    for (int i = s->top; i >= 0; --i) printf(" %d", s->items[i]);
    printf("\n");
}

int main(void) {
    Stack s;
    stack_init(&s);
    int choice, value;

    for (;;) {
        printf("\n1. Push  2. Pop  3. Peek  4. Display  5. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;  /* EOF or non-number */

        switch (choice) {
        case 1:
            printf("Value: ");
            if (scanf("%d", &value) != 1) return 0;
            if (stack_push(&s, value) == STACK_OVERFLOW) printf("Stack overflow\n");
            break;
        case 2:
            if (stack_pop(&s, &value) == STACK_UNDERFLOW) printf("Stack underflow\n");
            else printf("Popped %d\n", value);
            break;
        case 3:
            if (stack_peek(&s, &value) == STACK_UNDERFLOW) printf("Stack is empty\n");
            else printf("Top: %d\n", value);
            break;
        case 4:
            print_stack(&s);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
