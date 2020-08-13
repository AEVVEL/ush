#include "ush.h"

bool mx_ush_is_not_operator(char c) {
    if (c == '|' || c == '&' || c == '>' || c == '<'|| c == '$' || c == ' ')
        return false;
    if (c == 34 || c == 39 || c== 96 || c == 0 || c == '?')
        return false;
    if (c == '='|| c == 92)
        return false;
    return true;
}
