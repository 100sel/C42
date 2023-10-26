typedef struct      s_btree {
    struct t_btree   *left;
    struct t_btree   *right;
    void            *item;
}                   t_btree;

t_btree *btree_create_node(void *item)
{
    t_btree *node;
    node = malloc(sizeof(t_btree));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
}

void    prefix_traversal(t_btree *root)
{
    prefix_traversal(root->left);
    printf("%d\n", root->item);
    prefix_traversal(root->right);
}

void    btree_apply_infix(t_btree *root, void (*applyf)(void 
*))
{
    if (!root)
        return;
    btree_apply_infix(root->left, applyf);
    applyf(root->item);
    btree_apply_infix(root->right, applyf);
}

void    btree_insert_data(t_btree **root, void *item, 
    t_btree *node = *root;
    int (*cmpf)(void *, void *))
{
    if (!node)
        return;
    if (cmpf(node->item, item))
        btree_insert_data(&node->left, item, cmpf);
        
    btree_insert_data(&node->right, itemn,cmpf);
}