CC     ?= gcc
CFLAGS ?= -std=c99 -Wall -Wextra -O2
BUILD  := build

all: $(BUILD)/stack_demo

$(BUILD)/stack_demo: src/stack.c src/main.c src/stack.h | $(BUILD)
	$(CC) $(CFLAGS) src/stack.c src/main.c -o $@

$(BUILD)/test_stack: src/stack.c tests/test_stack.c src/stack.h | $(BUILD)
	$(CC) $(CFLAGS) -UNDEBUG src/stack.c tests/test_stack.c -o $@

test: $(BUILD)/test_stack
	./$(BUILD)/test_stack

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

.PHONY: all test clean
