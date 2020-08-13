#include "ush.h"

static bool is_ampersand(t_list *tmp) {
    if (mx_strcmp(((t_token*)tmp->data)->value[0], "&") == 0) {
        mx_printerr(MX_AMPERSAND);
        return true;
    }
    if (mx_strcmp(((t_token*)tmp->data)->value[0], "<<") == 0) {
        mx_printerr(MX_DLES);
        return true;
    }
    return false;
}

bool mx_check_tokens(t_list *tokens) {
    t_list *tmp = tokens;
    bool op = 0;

    if ((tokens == 0) || (mx_check_operator((t_token*)tmp->data)))
        return false;
    while(tmp->next) {
        if (mx_is_double_op(tmp, &op))
            return false;
        if (mx_is_double_more(tmp))
            return false;
        if (mx_is_double_less(tmp))
            return false;
        if (is_ampersand(tmp))
            return false;
        tmp = tmp->next;
    }
    if (mx_check_operator((t_token*)tmp->data))
        return false;
    return true;
}
