#ifndef PROJECT_TESTS_INCLUDE_TOOLS_H_
#define PROJECT_TESTS_INCLUDE_TOOLS_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "utils.h"

#define CASE_NUMBERS 3
#define OUT_FILE "out.txt"
#define IN_FILE "in.txt"

char* path_join(const char* base_path, const char* curr_path, const char* file_name, const int case_file);
void assert_strings_equals(const char* str1, const char* str2);

#endif // PROJECT_TESTS_INCLUDE_TOOLS_H_