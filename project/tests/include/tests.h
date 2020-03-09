#ifndef PROJECT_TESTS_INCLUDE_TESTS_H_
#define PROJECT_TESTS_INCLUDE_TESTS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "utils.h"

typedef void (*test_func)(const char *);

void test_count_letter(const char*);
void test_get_text(const char*);
void test_make_letter_list(const char*);
void test_print_letter_list(const char*);
void test_sort_letter_list(const char*);
void test_swap(const char*);

#endif // PROJECT_TESTS_INCLUDE_TESTS_H_