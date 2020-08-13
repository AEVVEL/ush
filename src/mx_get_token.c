#include "ush.h"

static void del_desc(char operator_status, int *fds) {
    if ((operator_status & OP_PIPE_W) || (operator_status & OP_MORE))
        close(fds[1]);
    if (operator_status & OP_PIPE_R)
        close(fds[0]);
}

static void child(t_token *token, char operator_status, int *fds) {
    if (operator_status & 23) {
            dup2(fds[1], 1);
            dup2(fds[0], 0);
        }
        mx_ush_begin_proces(token);
}

int mx_get_token(t_token *token, int *fds, char operator_status, t_info *info) {
    int exit_status = 0;
    pid_t pid = fork();

    if (pid == 0)
        child(token, operator_status, fds);
    else {
        del_desc(operator_status, fds);
        if (!(operator_status & OP_AMP)) {
            mx_sleeped_process(info, token->value);
            return exit_status;
        }
        else {
            if (mx_ush_add_proc(&(info->processes), pid, token->value) != -1)
                printf("Process [%d] created\n", pid);
            printf("pr = %d\n", ((t_process*)info->processes->data)->pid);
        }
    }
    return 1;
}
