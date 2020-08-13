#include "ush.h"

int mx_check_pipe(t_tnode *root, int *fds, char operator_status,
                    t_info *processes) {
    int status = 0;
    
    if ((operator_status & 3) == 0)
        status = mx_no_pipe(root, operator_status, processes);
    if (operator_status & OP_PIPE_R)
        status = mx_pipe_r(root, fds, operator_status, processes);
    return status;
}
