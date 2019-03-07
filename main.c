#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"


int main() {
  Node *root = NULL;
  root = insertBST(root, 5);
  insertBST(root, 3);
  insertBST(root, 2);
  insertBST(root, 1);
  insertBST(root, 4);
  insertBST(root, 7);
  insertBST(root, 6);
  insertBST(root, 3);
  insertBST(root, 8);

  //            5
  //          /   \
  //        3       7
  //       / \     / \
  //      2   4   6   8
  //     /
  //    1

  inOrder(root);
  printf("\nCzy jest drzewem BST? ");
  printANS(isBST(root, INT_MIN, INT_MAX));

  deleteBST(root, 5);

  //            5
  //          /   \
  //        3       8
  //       / \     /
  //      2   4   6
  //     /
  //    1

  inOrder(root);
  printf("\nCzy jest drzewem BST? ");
  printANS(isBST(root, INT_MIN, INT_MAX));

  int temp = root->key;             //
  root->key = root->left->key;      // break BST
  root->left->key = temp;           //

  inOrder(root);
  printf("\nCzy jest drzewem BST? ");
  printANS(isBST(root, INT_MIN, INT_MAX));


  // //            3
  // //          /   \
  // //        5       8
  // //       / \     /
  // //      2   4   6
  // //     /
  // //    1
  //

  return 0;
}
