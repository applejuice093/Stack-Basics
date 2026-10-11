CC     ?= gcc
CFLAGS ?= -std=c99 -Wall -Wextra -O2
BUILD  := build

all: $(BUILD)/stack_demo

$(BUILD)/stack_demo: src/stack.c src/main.c src/stack.h | $(BUILD)
	$(CC) $(CFLAGS) src/stack.c src/main.c -o $@

$(BUILD)/test_stack: src/stack.c tests/test_stack.c src/stack.h | $(BUILD)
	$(CC) $(CFLAGS) -UNDEBUG src/stack.c tests/test_stack.c -o $@

example: $(BUILD)/balanced_brackets

$(BUILD)/balanced_brackets: src/stack.c examples/balanced_brackets.c src/stack.h | $(BUILD)
	$(CC) $(CFLAGS) src/stack.c examples/balanced_brackets.c -o $@

$(BUILD)/test_brackets: src/stack.c examples/balanced_brackets.c tests/test_brackets.c | $(BUILD)
	$(CC) $(CFLAGS) -UNDEBUG -DNO_MAIN src/stack.c examples/balanced_brackets.c tests/test_brackets.c -o $@

test: $(BUILD)/test_stack $(BUILD)/test_brackets
	./$(BUILD)/test_stack
	./$(BUILD)/test_brackets

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

.PHONY: all test clean example
