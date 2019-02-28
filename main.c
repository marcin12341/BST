#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *parent;
};

Node *newNode(int key) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insertBST(Node *root, int key) {
    if (!root) {
        return newNode(key);
    } else if (key < root->key) {
        root->left = insertBST(root->left, key);
        root->left->parent = root;
    } else if (key > root->key) {
        root->right = insertBST(root->right, key);
        root->right->parent = root;
    }
    return root;
}

Node *minValue(Node *root) {
    Node *temp = root;
    while (temp->left) {
        temp = temp->left;
    }
    return temp;
}

void replace(Node *root, Node *newNode) {
    if (root == root->parent->left) {           // root to lewe dziecko
        root->parent->left = newNode;
    } else if (root == root->parent->right) {   // root to prawe dziecko
        root->parent->right = newNode;
    }
    if (newNode) {                              // przypnij nowego rodzica
        newNode->parent = root->parent;
    }
}

Node *deleteBST(Node *root, int key
) {
    if (!root) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteBST(root->left, key);
    } else if (key > root->key) {
        root->right = deleteBST(root->right, key);
    } else {
        if (!root->left && !root->right) {          // brak dzieci
            replace(root, NULL);
            free(root);
        } else if (root->left && root->right) {     // oboje dzieci
            Node *temp = minValue(root->right);
            root->key = temp->key;
            deleteBST(root->right, temp->key);
        } else if (root->left) {                    // tylko lewe dziecko
            replace(root, root->left);
            free(root);
        } else if (root->right) {                   // tylko prawe dziecko
            replace(root, root->right);
            free(root);
        }
    }
    return root;
}

int isBST(Node *root, int minKey, int maxKey) {
    if (!root) {
        return 1;
    }
    if (root->key < minKey || root->key > maxKey) {
        return 0;
    }
    return isBST(root->left, minKey, root->key - 1) && isBST(root->right, root->key + 1, maxKey);
}

void inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void printANS(int check) {
    if (check) {
        printf("TAK\n");
    } else {
        printf("NIE\n");
    }
}

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
    inOrder(root);
    printf("\n");
    deleteBST(root, 7);
    inOrder(root);
    printf("\n");
    printANS(isBST(root, INT_MIN, INT_MAX));

    Node *temp = root;  // break BST
    root = root->left;
    root->left = temp;

    printANS(isBST(root, INT_MIN, INT_MAX));
    return 0;
}
