#include "utils.h"
#include "tools.h"
#include "tests.h"

#define CASE_PATH "/test_print_letter_list/case_"

static void _test_print_letter_list(const char* in, const char* out);

void _test_print_letter_list(const char* in, const char* out) {
    FILE* file_in = fopen(in, "r");
    FILE* file_out = fopen(out, "w");

    size_t text_size = 0, list_size = 0;
    char* in_text = get_text(file_in, &text_size);
    letter_frequency_t* list = make_letter_list(in_text, text_size, &list_size);
    print_letter_list(file_out, list, list_size);
    fclose(file_out);
    file_out = fopen(out, "r");
    char* out_text = get_text(file_out, &text_size);
    for (size_t i = 0; i < list_size; ++i) {
        assert(out_text[i] == list[i].letter);
    }

    free(list);
    free(in_text);
    free(out_text);
    fclose(file_out);
    fclose(file_in);
}

void test_print_letter_list(const char* base_path) {
    printf("Testing print_letter_list function");
    for (int i = 1; i <= CASE_NUMBERS; ++i) {
        char* path_in_file = path_join(base_path, CASE_PATH, IN_FILE, i);
        char* path_out_file = path_join(base_path, CASE_PATH, OUT_FILE, i);

        _test_print_letter_list(path_in_file, path_out_file);
        printf(".");

        free(path_in_file);
        free(path_out_file);
    }
    printf("OK!\n");
}