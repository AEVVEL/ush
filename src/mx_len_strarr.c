#include "ush.h"

int mx_len_strarr(char **str) {
    int count = 0;

    while (str[count]) 
        count++;
    return count;
}
