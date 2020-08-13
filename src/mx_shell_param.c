#include "ush.h"

void mx_shell_param(t_info *processes, int *i, char **new_str) {
    int end = *i;
    int flag = 0;
    char *par_shell = 0;

    flag = mx_corect_end_of_flag(*new_str, &end, mx_strlen(*new_str), '}');
    if (flag != 0) {
        mx_strdel(new_str);
        *new_str = mx_strnew(0);
        *i = 0;
    }
    else {
        mx_strdel(&par_shell);
        par_shell = mx_strndup(&new_str[0][*i + 2], end - *i - 3);
        par_shell = mx_get_value(&par_shell, &(processes->var_tree));
        mx_replace(new_str, *i, end, par_shell);
        if (par_shell)
            *i += mx_strlen(par_shell);
    }
}
