#ifndef BST_H
#define BST_H

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function declarations
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* delete(Node* root, int data);
Node* search(Node* root, int data);

void inorderRecursive(Node* root);
void inorderNonRecursive(Node* root);
void preorderRecursive(Node* root);
void preorderNonRecursive(Node* root);
void postorderRecursive(Node* root);
void postorderNonRecursive(Node* root);
void levelOrderTraversal(Node* root);

#endif

