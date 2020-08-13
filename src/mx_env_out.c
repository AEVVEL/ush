#include "ush.h"

void mx_env_out(t_var *var) { 
    while (var) {
        if (var->flag) {
            printf("%s\n", var->value);
        }
        var = var->next;
    }
}
