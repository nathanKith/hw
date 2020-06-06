#include "utils.h"
#include "tools.h"
#include "tests.h"

#define CASE_PATH "/test_make_letter_list/case_"

static void _test_make_letter_list(const char* in);

void _test_make_letter_list(const char* in) {
    FILE* file = fopen(in, "r");
    size_t string_size = 0;
    char* string = get_text(file, &string_size);
    size_t res_list_size = 0;

    letter_frequency_t* res_list = make_letter_list(string, string_size, &res_list_size);
    for(size_t i = 0; i < res_list_size; ++i) {
        char letter = res_list[i].letter;
        size_t letter_number = count_letter(letter, string, string_size) +
                               count_letter(letter + 'A' - 'a', string, string_size);
        assert(res_list[i].number == letter_number);
    }

    free(string);
    free(res_list);
    fclose(file);
}

void test_make_letter_list(const char* base_path) {
    printf("Testing make_letter_list function");
    for (int i = 1; i <= CASE_NUMBERS; ++i) {
        char* path_file = path_join(base_path, CASE_PATH, IN_FILE, i);
        _test_make_letter_list(path_file);
        printf(".");
        free(path_file);
    }
    printf("OK!\n");
}