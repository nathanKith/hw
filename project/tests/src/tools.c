#include "tools.h"

char* path_join(const char* base_path, const char* curr_path, const char* file_name, const int case_file) {
    size_t sz = strlen(base_path) + strlen(curr_path) + strlen(file_name) + 3;
    char* path = malloc(sizeof(*path) * sz);
    if (!path) {
        return NULL;
    }
    snprintf(path, sizeof(*path) * sz, "%s%s%d/%s", base_path, curr_path, case_file, file_name);
    return path;
}

void assert_strings_equals(const char* str1, const char* str2) {
    for(int i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i) {
        assert(str1[i] == str2[i]);
    }
}