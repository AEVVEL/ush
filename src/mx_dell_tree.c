#include "ush.h"

void mx_dell_tree(t_tnode **root) {
    if ((*root)->right != 0) {
        mx_dell_tree(&(*root)->right);
    }
    if ((*root)->left != 0) {
        mx_dell_tree(&(*root)->left);
    }
    if (((*root)->left == 0) && ((*root)->right == 0)) {
        mx_del_strarr(&(((t_token*)(*root)->data)->value));
        free((*root)->data);
        free(*root);
        *root = 0;
    }
}
