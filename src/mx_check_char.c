#include "ush.h"

bool mx_check_char(char c) {
    if ((c == '|') || (c == '&') || (c == '>') || (c == '<')
        || (c == ' ') || (c == '\n') || (c == ';') || (c == '\0'))
        return false;
    return true;  
}
