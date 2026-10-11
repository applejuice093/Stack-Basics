# Stack-Basics

A small, well-tested stack (LIFO) of integers implemented in C on top of a
fixed-size array, plus an interactive demo and a practical example.

## What is a stack?

A stack stores items so that the **last item pushed is the first one popped**
(Last In, First Out). Think of a pile of plates. It is used for undo
history, function calls, expression parsing and depth-first search.

| Operation  | What it does                         | Cost |
|------------|--------------------------------------|------|
| `push`     | add an item on top                   | O(1) |
| `pop`      | remove and return the top item       | O(1) |
| `peek`     | read the top item without removing   | O(1) |
| `is_empty` / `is_full` / `size` | query state     | O(1) |

## Project structure

```text
├── src/stack.h, src/stack.c        # the stack itself
├── src/main.c                      # interactive menu demo
├── examples/balanced_brackets.c    # checks (), [] and {} nesting
├── tests/                          # unit tests (make test)
└── Makefile
```

## Build and run

Requires a C99 compiler (gcc or clang) and `make`.

```bash
make                     # builds build/stack_demo
./build/stack_demo       # interactive menu: push, pop, peek, display
make example
./build/balanced_brackets "{[()]}"   # -> balanced
make test                # runs all unit tests
```

Without make:

```bash
gcc -std=c99 -Wall src/stack.c src/main.c -o stack_demo
```

## Using the stack in your own code

```c
#include "stack.h"

Stack s;
int top;
stack_init(&s);
stack_push(&s, 42);
if (stack_pop(&s, &top) == STACK_OK) {
    /* top == 42 */
}
```

Every operation that can fail returns `STACK_OK`, `STACK_OVERFLOW` (push on a
full stack) or `STACK_UNDERFLOW` (pop/peek on an empty stack) instead of
printing or exiting, so the caller decides how to react. Capacity is set by
`STACK_MAX` in `src/stack.h` (default 100).

## License

MIT, see [LICENSE](LICENSE).
