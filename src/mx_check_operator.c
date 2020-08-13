#include "ush.h"

bool mx_check_operator(t_token *token) {
    if ((token->type ==  TYPE_OPERATOR) && (token->priority != 20)) {
        mx_printerr("u$h: Error near");
        mx_printerr(token->value[0]);
        mx_printerr("\n");
        return true;
    }
    return false;
}
