#include "ush.h"

bool mx_is_double_op(t_list *tmp, bool *op) {
    if (((t_token *)tmp->data)->type == TYPE_OPERATOR) {
        if (*op) {
            mx_printerr("\033[1;31mu$h: Error near \'");
            mx_printerr(((t_token *)tmp->data)->value[0]);
            mx_printerr("\'\033[0m\n");
            return true;
        }
        *op = true;
    }
    else
        *op = false;
    if ((tmp->next == 0) && (*op)) {
        mx_printerr("\033[1;31mu$h: Error near \'");
        mx_printerr(((t_token *)tmp->data)->value[0]);
        mx_printerr("\'\033[0m\n");
        return false;
    }
    return false;
}

bool mx_is_double_more(t_list *tmp) {
    char *value = ((t_token *)tmp->data)->value[0];

    if ((mx_strcmp(value, ">") == 0) || (mx_strcmp(value, ">>") == 0)) {
        if ((tmp->next) && (tmp->next->next) 
        && ((mx_strcmp(((t_token *)tmp->next->next->data)->value[0], ">") == 0 
        || mx_strcmp(((t_token *)tmp->next->next->data)->value[0], ">>") == 0 
        || mx_strcmp(((t_token *)tmp->next->next->data)->value[0], "<") == 0))) {
            mx_printerr("\033[1;31mu$h: Error near \'");
            mx_printerr(value);
            mx_printerr("\'\033[0m\n");
            return true;
        }
    }
    return false;
}

bool mx_is_double_less(t_list *tmp) {
    char *value = ((t_token *)tmp->data)->value[0];

    if ((mx_strcmp(value, "<") == 0) || (mx_strcmp(value, ">") == 0)) {
        if ((tmp->next) && (tmp->next->next) 
        && ((mx_strcmp(MX_PATH, "<") == 0) || (mx_strcmp(MX_PATH, ">") == 0))) {
            mx_printerr("\033[1;31mu$h: Error near \'");
            mx_printerr(value);
            mx_printerr("\'\033[0m\n");
            return true;
        }
    }
    return false;
}
