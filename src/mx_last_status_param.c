#include "ush.h"

void mx_last_status_param(t_info *processes, int *i, char **new_str, int flag) {
    char *par_shell = 0;

    par_shell = mx_itoa(processes->last_status);
    mx_replace(new_str, *i, flag, par_shell);
    if (par_shell) {
        *i += mx_strlen(par_shell);
        mx_strdel(&par_shell);
    }
}
