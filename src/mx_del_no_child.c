#include "ush.h"

void mx_delete_no_child(t_tnode **root, void *data,
                            int (*cmp)(void*, void*),
                            void (*free_tnode)(t_tnode *tnode)) {
    t_tnode *root_ = *root;
    int result = cmp(root_->data, data);

    if (result == 0) {
        free_tnode(*root);
        *root = 0;
    }
    else if (result > 0) {
       mx_delete_no_child(&((*root)->left), data, cmp, free_tnode);
    }
    else {
        mx_delete_no_child(&((*root)->right), data, cmp, free_tnode);
    }
}
