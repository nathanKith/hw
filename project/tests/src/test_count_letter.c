#include "utils.h"
#include "tools.h"
#include "tests.h"

#define CASE_PATH "/test_count_letter/case_"

static void _test_count_letter_list(const char* in);

void _test_count_letter_list(const char* in) {
    FILE* file = fopen(in, "r");
    size_t sz = 0;
    size_t result = 0;
    char* text = get_text(file, &sz);
    size_t size = sz;
    for (size_t i = 0; i < size; ++i) {
        if (!((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))) {
            --sz;
        }
    }

    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        result += count_letter(letter, text, size) + count_letter(letter + 'a' - 'A', text, size);
    }

    free(text);
    fclose(file);

    assert(result == sz);
}


void test_count_letter(const char* base_path) {
    printf("Testing count_letter function");
    for (int i = 1; i <= CASE_NUMBERS; ++i) {
        char* path_file = path_join(base_path, CASE_PATH, IN_FILE, i);
        _test_count_letter_list(path_file);

        printf(".");

        free(path_file);
    }
    printf("OK!\n");
}