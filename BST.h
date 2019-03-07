#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

Node *newNode(int key);

Node *insertBST(Node *root, int key);

Node *minValue(Node *root);

void replace(Node *root, Node *newNode);

Node *deleteBST(Node *root, int key);

int isBST(Node *root, int minKey, int maxKey);

void inOrder(Node *root);

void printANS(int check);
