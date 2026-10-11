/* balanced_brackets.c - Classic stack use case: check that (), [] and {}
 * are properly nested in a string.
 *
 * Build: make example   Run: ./build/balanced_brackets "{[()]}"
 */
#include <stdio.h>

#include "../src/stack.h"

static int matches(int open, int close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int is_balanced(const char *text) {
    Stack s;
    stack_init(&s);
    for (const char *p = text; *p; ++p) {
        int top;
        switch (*p) {
        case '(': case '[': case '{':
            if (stack_push(&s, *p) != STACK_OK) return 0;  /* too deep */
            break;
        case ')': case ']': case '}':
            if (stack_pop(&s, &top) != STACK_OK || !matches(top, *p)) return 0;
            break;
        }
    }
    return stack_is_empty(&s);  /* leftover openers mean unbalanced */
}

#ifndef NO_MAIN
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s \"expression\"\n", argv[0]);
        return 2;
    }
    int ok = is_balanced(argv[1]);
    printf("%s\n", ok ? "balanced" : "not balanced");
    return ok ? 0 : 1;
}
#endif
