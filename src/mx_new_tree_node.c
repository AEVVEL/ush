#include "ush.h"

t_tnode *mx_new_tree_node(void *data) {
    t_tnode *new_node = (t_tnode*)malloc(sizeof(t_tnode));

    new_node->data = data;
    new_node->left = 0;
    new_node->right = 0;
    new_node->parent = 0;
    return new_node;
}
