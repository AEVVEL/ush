#include "ush.h"

char *mx_ush_get_new_pwd(char *path, t_info *info) {
    char **tokens = mx_strsplit(path, '/');
    char *tmp_pwd = path[0] == '/' ? mx_strdup("/") : mx_strdup(info->pwd_l);
    char *res = 0;

    for (int i = 0; tokens[i]; i++)
        if (mx_strcmp(tokens[i], "..") == 0) {
            if (mx_ush_get_rank(tmp_pwd) == 0)
                continue;
            tmp_pwd = mx_dell_back_rank(tmp_pwd);
        }
        else 
            tmp_pwd = mx_ush_add_rank(tmp_pwd, tokens[i]);
    if (tmp_pwd[0] != '/') {
        res = mx_strjoin("/", tmp_pwd);
        free(tmp_pwd);
    }
    else
        res = tmp_pwd;
    mx_del_strarr(&tokens);
    return res;
}
