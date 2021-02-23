typedef struct n_AVL {
  int key;
  int bal;
  struct n_AVL *c_left, *c_right;
} node_avl, *Tree_AVL_t ;

/* type Arbre AVL, pointeur vers un noeud */

Tree_AVL_t create_avl (int key);
Tree_AVL_t rotation_left (Tree_AVL_t a);
Tree_AVL_t rotation_right (Tree_AVL_t a);
Tree_AVL_t double_rotation_left (Tree_AVL_t a);
Tree_AVL_t double_rotation_right (Tree_AVL_t a);
Tree_AVL_t balancing (Tree_AVL_t a);
Tree_AVL_t insert_key (Tree_AVL_t a, int key);
void show_avl (Tree_AVL_t a, int level);
int height_avl (Tree_AVL_t a);

