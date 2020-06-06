#ifndef _HOME_NATHANKITH_HW_PROJECT_INCLUDE_UTILS_H_
#define _HOME_NATHANKITH_HW_PROJECT_INCLUDE_UTILS_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct letter_frequency_t {
    size_t number;
    char letter;
} letter_frequency_t;

void sort_letter_list(letter_frequency_t* letter_list, const size_t letter_list_length);

char* get_text(FILE* file, size_t* size);

letter_frequency_t* make_letter_list(const char* text, const size_t text_length, size_t* letter_list_size);

size_t count_letter(const char letter, const char* text, size_t text_length);

void print_letter_list(FILE* file, const letter_frequency_t* letter_list, const size_t letter_list_length);


#endif  // _HOME_NATHANKITH_HW_PROJECT_INCLUDE_UTILS_H_
