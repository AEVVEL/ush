#include "ush.h"

void mx_susp_out(char **mas_name) {
    char *name = mx_arrstr_to_str(mas_name);

    printf("\nush: suspended %s\n", name);
    free(name);
}
