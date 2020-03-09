#include "tests.h"
#include <signal.h>

#define BASE_DIR "./project/tests/data"
#define TEST_NUM 5

static test_func tests[] = {
        test_count_letter,
        test_get_text,
        test_make_letter_list,
        test_print_letter_list,
        test_sort_letter_list
};

void pppp(int signum) {
    signal(signum, SIG_DFL);
    exit(3);
}

int main() {
    signal(SIGSEGV, pppp);
    for (size_t i = 0; i < TEST_NUM; ++i) {
        tests[i](BASE_DIR);
    }
    printf("SUCCESS\n");
    return 0;
}