#include "ush.h"

void mx_characteristic_shell(t_info *processes, int *i, char **new_str) {
    int flag = mx_param_ush_end(*new_str, *i);
    char *par_shell = 0;

    par_shell = mx_strndup(&new_str[0][*i + 1], flag - *i - 1);
    if (par_shell[0] == '?') {
        mx_strdel(&par_shell);
        mx_last_status_param(processes, i, new_str, flag);
    }
    else if (par_shell[0] == '{') {
        mx_strdel(&par_shell);
        mx_shell_param(processes, i, new_str);
    }
    else {
        par_shell = mx_get_value(&par_shell, &(processes->var_tree));
        mx_replace(new_str, *i, flag, par_shell);
        if (par_shell)
            *i += mx_strlen(par_shell);
    }
    (*i)--;
}
