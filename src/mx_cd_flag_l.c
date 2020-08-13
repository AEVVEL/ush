#include "ush.h"

int mx_cd_flag_l(char *path, t_info *info, char flags) {
    char *new_pwd = 0;

    if (path == 0)
        return 0;
    new_pwd = mx_ush_get_new_pwd(path, info);
    if (chdir(new_pwd) == -1) {
        if ((flags & 1) == 0)
        fprintf(stderr, "cd: %s: %s\n", strerror(errno), new_pwd);
        free(new_pwd);
        return 1;
    }
    free(info->old_pwd);
    info->old_pwd = info->pwd;
    free(info->pwd_l);
    info->pwd_l = new_pwd;
    free(info->pwd_p);
    info->pwd_p = getcwd(NULL, 0);
    info->pwd = mx_strdup(info->pwd_l);
    return 0;
}
