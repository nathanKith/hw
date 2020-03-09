/* Составить программу обработки введённого пользователем текста. 
В качестве входа она принимает текст произвольной длины, 
на выходе – формирует список букв в порядке, обратном их встречаемости в тексте. 
Процедуру обработки текста оформить в виде отдельной функции. Пользоваться 
стандартными функциями сортировки и работы со строками запрещается - необходимо их реализовать вручную. */

#include "utils.h"

int main() {
    size_t text_length = 0;
    char *text = get_text(stdin, &text_length);
    if (!text) {
        printf("Error. The text cannot be read or you didn't enter it.");
        return -1;
    }

    size_t letter_list_length = 0;
    letter_frequency_t* letter_list = make_letter_list(text, text_length, &letter_list_length);
    if (!letter_list) {
        printf("Error. There are some problems or there are no english letters in the text");
        return -1;
    }

    sort_letter_list(letter_list, letter_list_length);

    print_letter_list(stdout, letter_list, letter_list_length);
    free(text);
    free(letter_list);

    return 0;
}
