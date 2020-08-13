#include "ush.h"

void mx_free_path_for_env(t_var *var, char *path) {
    t_var *tmp = NULL;

    if (path) {
        free(path);
        path = NULL;
    }
    while (var) {
        tmp = var;
        var = var->next;
        if (tmp->value)
            free(tmp->value);
        if (tmp->name)
            free(tmp->name);
        free(tmp);
    }
}
