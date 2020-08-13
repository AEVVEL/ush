#include "ush.h"

char *mx_get_value(char **str, t_list **var_tree) {
    t_list *temp = *var_tree;

    while (temp) {
        if (mx_strcmp(*str, ((t_variable*)temp->data)->name) == 0) {
            mx_strdel(str);
            return ((t_variable *)temp->data)->value;
        }
        temp = temp->next;
    }
    mx_strdel(str);
    return 0;
}

char *mx_get_value_new(const char *str, t_list **var_tree) {
    t_list *temp = *var_tree;

    while (temp) {
        if (mx_strcmp(str, ((t_variable*)temp->data)->name) == 0)
            return ((t_variable*)temp->data)->value;
        temp = temp->next;
    }
    return 0;
}
