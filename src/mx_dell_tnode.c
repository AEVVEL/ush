#include "ush.h"

void mx_delete_tnode_1ch(t_tnode **root, void *data,
                             int (*cmp)(void*, void*),
                             void (*free_tnode)(t_tnode *tnode)) {
    t_tnode *del_node = 0;

    if ((root == 0) || (*root == 0))
        return;
    if (cmp((*root)->data, data) == 0) {
        if ((*root)->right != 0) {
            del_node = *root;
            *root = (*root)->right;
            free_tnode(del_node);
        }
        else if ((*root)->left != 0) {
            del_node = *root;
            *root = (*root)->left;
            free_tnode(del_node);
        }
    }
    else if (cmp((*root)->data, data) > 0)
        mx_delete_tnode_1ch(&((*root)->left), data, cmp, free_tnode);
    else
        mx_delete_tnode_1ch(&((*root)->right), data, cmp, free_tnode);
}

void mx_delete_tnode_2ch(t_tnode **root, int (*cmp)(void*, void*),
                             t_tnode *finded,
                             void (*free_tnode)(t_tnode *tnode)) {
    t_tnode *min = mx_take_min_tree_node(finded->right);

    mx_clear_tree_node(root, min->data, cmp, free_tnode);
    finded->data = min->data;
}
