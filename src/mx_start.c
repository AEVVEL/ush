#include "ush.h"

void mx_start(char **commands, t_info *processes) {
    t_list  *tokens  = NULL;
    t_tnode *root_ast = 0;
    int i = 0;

    while (commands[i]) {
        tokens = mx_take_info(commands[i], processes);
        if (processes->if_ctrl_c && mx_check_tokens(tokens)) {
            root_ast = mx_create_tree(&tokens, 0);
            mx_start_prog_tree(root_ast, 0, 0, processes);
            mx_dell_tree(&root_ast);
        }
        else
            mx_dell_tokens(&tokens);
        if (!(processes->if_ctrl_c))
            while (commands[++i]);
        else
            i++;
    }
}
