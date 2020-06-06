#include "utils.h"

static size_t partition(letter_frequency_t*, size_t);
static void swap(letter_frequency_t* l, letter_frequency_t* r);

char* get_text(FILE* file, size_t* size) {
    char *buffer = NULL;
    char ch;
    *size = 0;
    for (; (ch = fgetc(file)) != '\n'; ++(*size)) {
        char* check = realloc(buffer, *size + 2);
        if (!check)  {
            break;
        }
        buffer = check;
        buffer[*size] = ch;
        buffer[*size + 1] = '\0';
    }
    if (!buffer) {
        return NULL;
    }
    if (buffer[*size] != '\0') {
        free(buffer);
        return NULL;
    }
    return buffer;
}

letter_frequency_t* make_letter_list(const char* text, const size_t text_length, size_t* letter_list_size) {
    letter_frequency_t* list = NULL;
    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        if (count_letter(letter, text, text_length) ||
            count_letter(letter + 'a' - 'A', text, text_length)) {
            letter_frequency_t* check = realloc(list, ++(*letter_list_size) * sizeof(*check));
            if (!check) {
                free(list);
                return NULL;
            }
            list = check;
            list[*letter_list_size - 1].letter = letter + 'a' - 'A';
            list[*letter_list_size - 1].number = count_letter(letter, text, text_length) +
                                                 count_letter(letter + 'a' - 'A', text, text_length);
        }
    }
    return list;
}

size_t count_letter(const char letter, const char* text, size_t text_length) {
    if (!text) {
        return 0;
    }
    size_t number = 0;
    for (size_t i = 0; i < text_length; ++i) {
        if (text[i] == letter) {
            ++number;
        }
    }
    return number;
}

void swap(letter_frequency_t* l, letter_frequency_t* r) {
    letter_frequency_t tmp = {
            .number = l->number,
            .letter = l->letter
    };
    l->number = r->number;
    l->letter = r->letter;
    r->number = tmp.number;
    r->letter = tmp.letter;
}

size_t partition(letter_frequency_t* letter_list, size_t letter_list_length) {
    if (letter_list_length <= 1) {
        return 0;
    }
    const size_t pivot = letter_list[letter_list_length - 1].number;
    int i = 0, j = letter_list_length - 2;
    while (i <= j) {
        for (; letter_list[i].number < pivot; ++i) {}
        for (; j >= 0 && letter_list[j].number >= pivot; --j) {}
        if (i < j) {
            swap(&letter_list[i++], &letter_list[j--]);
        }
    }
    swap(&letter_list[i], &letter_list[letter_list_length - 1]);
    return i;
}

void sort_letter_list(letter_frequency_t* letter_list, const size_t letter_list_length) {
    if (!letter_list) {
        return;
    }
    size_t part = partition(letter_list, letter_list_length);
    if (part > 0) {
        sort_letter_list(letter_list, part);
    }
    if (part + 1 < letter_list_length) {
        sort_letter_list(letter_list + part + 1, letter_list_length - (part + 1));
    }
}

void print_letter_list(FILE* file, const letter_frequency_t* letter_list, const size_t letter_list_length) {
    for (size_t i = 0; i < letter_list_length; ++i) {
        fprintf(file, "%c", letter_list[i].letter);
    }
    fprintf(file, "\n");
}
