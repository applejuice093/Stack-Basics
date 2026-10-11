/* test_brackets.c - Tests for the balanced-brackets example. */
#include <assert.h>
#include <stdio.h>

int is_balanced(const char *text);

int main(void) {
    assert(is_balanced(""));
    assert(is_balanced("a + (b * [c - {d}])"));
    assert(!is_balanced("(]"));
    assert(!is_balanced("(()"));
    assert(!is_balanced("())"));
    printf("Bracket tests passed\n");
    return 0;
}
