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
