#ifndef USH_H
#define USH_H

#include "libmx.h"
#include "macroses.h"
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <regex.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <term.h>
#include <termcap.h>
#include <time.h>
#include <unistd.h>
#include <xlocale.h>

typedef struct s_var {
    char *name;
    char *value;
    bool flag;
    struct s_var *next;
}              t_var;

typedef struct s_variable {
    char *name;
    char *value;
    bool is_env;
    char *mem;
}              t_variable;

typedef struct s_tree_node {
    struct s_tree_node *left;
    struct s_tree_node *right;
    struct s_tree_node *parent;
    void *data;
} t_tnode;

enum e_branch
{
    RIGHT,
    LEFT
};

enum e_operator_status { 
    OP_NOTHING,
    OP_PIPE_R,
    OP_PIPE_W,
    OP_PIPE_RW,
    OP_MORE = 4,
    OP_DMORE = 8,
    OP_LESS = 16,
    LEFT_VISITED = 128,
    RIGHT_VISITED = 64,
    OP_AMP = 32
};

enum e_type_of_token{
    TYPE_OPERATOR,
    TYPE_COMMAND,

    TYPE_FILENAME,
    TYPE_DESC_NUMB,
};

typedef struct s_token{
    char type;
    char **value;
    int priority;
}              t_token;

typedef struct s_process {
    char **name;
    pid_t pid;
    int index;
}              t_process;

typedef struct s_input {
    char **comands;
    char **comand_tab;
    int id;
    int max_comand;
    int str_len;
    int end_posit;
    int if_;
    int pos_tab;
}              t_input;

typedef struct s_programInfo {
    struct termios term_old;
    struct termios term_new;
    char **env;
    t_list *history;
    t_input *input;
    t_list *processes;
    bool is_exit;
    bool if_ctrl_c;
    int exit_status;
    char *pwd;
    char *pwd_l;
    char *pwd_p;
    char *old_pwd;
    char *path;
    char *home;
    t_list *var_tree;
    int last_status;
}              t_info;

enum e_keys{
    CTRL_A = 1,
    CTRL_W = 23,
    CTRL_E = 5,
    CTRL_R = 18,
    CTRL_T = 20,
    CTRL_Y = 25,
    CTRL_U = 21,
    CTRL_I = 9,
    CTRL_P = 16,
    CTRL_CLOSE_BRACKET = 29,
    CTRL_D = 4,
    CTRL_F = 6,
    CTRL_G = 7,
    CTRL_H = 8,
    CTRL_K = 11,
    CTRL_L = 12,
    CTRL_Z = 26,
    CTRL_X = 24,
    CTRL_C = 3,
    CTRL_B = 2,
    CTRL_N = 14,
    KEY_ESCAPE = 27,
    KEY_SPACE = 32,
    KEY_ENTER = 13
};

#endif
