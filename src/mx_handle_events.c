#include "ush.h"

int mx_handle_events(char ch) {
    if (ch == KEY_ENTER) {
        return KEY_ENTER;
    }
    if (ch == CTRL_I)
        return 9;
    if (ch == CTRL_D) {
        return -1;
    }
    if (ch == CTRL_Z) {
        write(1, "\a", 1);
    }
    if (ch == CTRL_C)
        return 2;
    if (ch == CTRL_R)
        return 18;
    return 0;
}
