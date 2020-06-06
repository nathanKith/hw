#include "utils.h"
#include "tools.h"
#include "tests.h"

#define CASE_PATH "/test_get_text/case_"

static char* test_case[] = {
        "AaAa bb BBB",
        "21345 ddd &&&",
        NULL
};

static void _test_get_text(const char* in, const char* case_string);

void _test_get_text(const char* in, const char* case_string) {
    FILE* file = fopen(in, "r");
    size_t size = 0;
    char* test_string = get_text(file, &size);
    if (!test_string && !case_string) {
        fclose(file);
        return;
    }
    assert_strings_equals(test_string, case_string);
    free(test_string);
    fclose(file);
}

void test_get_text(const char* base_path) {
    printf("Testing get_text function");
    for (int i = 1; i <= CASE_NUMBERS; ++i) {
        char* path_file = path_join(base_path, CASE_PATH, IN_FILE, i);
        _test_get_text(path_file, test_case[i - 1]);
        printf(".");
        free(path_file);
    }
    printf("OK!\n");
}