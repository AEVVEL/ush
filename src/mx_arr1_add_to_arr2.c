#include "ush.h"

void mx_arr1_add_to_arr2(char ***strs, char ***str) {
    int count = 0;
    int count2 = 0;

    if ((strs == 0) || (str == 0))
        return;
    if (*strs == 0) {
        *strs = *str;
        return;
    }
    count = mx_len_strarr(*strs);
    count2 = mx_len_strarr(*str);
    *strs = (char **) realloc(*strs, sizeof(char *) * (count  + count2 + 1));
    count2 = 0;
    while ((*str)[count2]) {
        (*strs)[count++] = (*str)[count2++];
    }
    (*strs)[count] = 0;
    free(*str);
    return;
}
