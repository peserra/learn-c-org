#include <_stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
  int val;
  node *left;
  node *right;
}; 

void insert(node **tree, int val);
void print_tree(node *tree);
void print_dfs(node *tree);
node *create_node(int val);

int main(){
  node *tree = {0};
  insert(&tree, 0);
  insert(&tree, 5);
  insert(&tree, 8);
  insert(&tree, 4);
  insert(&tree, 3);
  print_tree(tree);
  printf("\n");
  print_dfs(tree);
  printf("\n");
  return 0;
}

node *create_node(int val){
  node *new_node = malloc(sizeof(node));
  if (new_node == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  new_node->val = val;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}


void insert(node **tree, int val){

  if (*tree == NULL) {
    *tree = create_node(val);
    return;
  }

  if (val < (*tree)->val){
    insert(&(*tree)->left, val);
  } else {
    insert(&(*tree)->right, val);
  }
 }

void print_tree(node *tree){
  if (tree == NULL) return;
  if (tree->left != NULL) print_tree(tree->left);
  if (tree != NULL) printf(" %d", tree->val);
  if (tree->right != NULL) print_tree(tree->right);
}

void print_dfs(node *tree){
  if (tree == NULL) return;
  if (tree != NULL) printf(" %d", tree->val);
  if (tree->left != NULL) print_dfs(tree->left);
  if (tree->right != NULL) print_dfs(tree->right);
}

