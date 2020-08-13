#include "ush.h"

t_tnode *mx_select_tree_node(t_tnode *root, void *data, int (*cmp)(void*, void*)) {
    t_tnode *finded = 0;

    if (root == 0)
        return 0;
    if (cmp(root->data, data) == 0)
        finded = root;
    else if (cmp(root->data, data) < 0) {
        if (root->right == 0)
            return 0;
        else
            finded = mx_select_tree_node(root->right, data, cmp);
    }
    else {
        if (root->left == 0)
            return 0;
        else
            finded = mx_select_tree_node(root->left, data, cmp);
    }
    return finded;
}
