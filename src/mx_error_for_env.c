#include "ush.h"

static void all_false(t_var *var) {
    while (var) {
        var->flag = 0;
        var = var->next;
    }
}

static bool get_path(char **path, int *i, char **argv) {
    if (*path)
        free(*path);
    *path = mx_get_path_for_env(argv[*i], argv[*i + 1], i);
    if (*path == NULL) {
        mx_print_error_for_env(argv[*i - 1], 0);
        return 1;
    }
    return 0;
}

bool mx_error_for_env(char **argv, char **path, t_var *var, int *i) {
    if (strcmp(argv[*i], "=") == 0 && mx_print_error_for_env(NULL, 2))
        return 1;
    else if (mx_ush_regular(argv[*i], MX_REG_ERR)) {
        mx_print_error_for_env(argv[*i], 1);
        return 1;
    }
    else if (mx_ush_regular(argv[*i], MX_REG_P)) {
        if (get_path(path, i, argv))
            return 1;
    }
    else if (mx_ush_regular(argv[*i], MX_REG_U))
        if (mx_dell_var_for_env(argv[*i], argv[*i + 1], var, i)) {
            mx_print_error_for_env(argv[*i - 1], 0);
            return 1;
        }
    if (mx_ush_regular(argv[*i - 1], MX_REG_I) || mx_ush_regular(argv[*i], MX_REG_I))
        all_false(var);
    return 0;
}
