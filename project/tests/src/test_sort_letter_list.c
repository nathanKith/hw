#include "utils.h"
#include "tools.h"
#include "tests.h"

#define CASE_PATH "/test_sort_letter_list/case_"

static void _test_sort_letter_list(const char* in);

void _test_sort_letter_list(const char* in) {
    FILE* file = fopen(in, "r");
    size_t text_size = 0;

    char* text = get_text(file, &text_size);
    size_t list_size = 0;

    letter_frequency_t* list = make_letter_list(text, text_size, &list_size);
    sort_letter_list(list, list_size);

    for (size_t i = 0; i < list_size - 1; ++i) {
        assert(list[i].number <= list[i + 1].number);
    }

    free(text);
    free(list);
    fclose(file);
}

void test_sort_letter_list(const char* base_path) {
    printf("Testing sort_letter_list function");
    for (int i = 1; i <= CASE_NUMBERS; ++i) {
        char* path_file = path_join(base_path, CASE_PATH, IN_FILE, i);

        _test_sort_letter_list(path_file);
        printf(".");

        free(path_file);
    }
    printf("OK!\n");
}