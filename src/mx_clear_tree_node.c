#include "ush.h"

void mx_clear_tree_node(t_tnode **root, void *data, int (*cmp)(void*, void*),
                     void (*free_tnode)(t_tnode *tnode)) {
    t_tnode *finded = mx_select_tree_node(*root, data,  cmp);

    if (finded == 0)
        return;
    if (finded == *root) {
        printf("ROOTTT\n");
        free_tnode(finded);
    }
    if (finded == 0)
        return;
    if ((finded->left == 0) && (finded->right == 0))
        mx_delete_no_child(root, data, cmp, free_tnode);
    else if ((finded->left == 0) && (finded->right != 0))
        mx_delete_tnode_1ch(root, data, cmp, free_tnode);
    else if ((finded->left != 0) && (finded->right == 0))
        mx_delete_tnode_1ch(root, data, cmp, free_tnode);
    else if ((finded->right != 0) && (finded->left !=0))
        mx_delete_tnode_2ch(root, cmp, finded, free_tnode);
}
