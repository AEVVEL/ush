#include "ush.h"

int mx_param_ush_end(char *str, int i) {
    int temp = i + 1;

    while (mx_ush_is_not_operator(str[temp]))
        temp++;
    if (str[temp] == '?' && str[temp + 1] != '(')
        temp++;
    return temp;
}
