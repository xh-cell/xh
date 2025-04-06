#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {
    Node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Test search
    Node* result = search(root, 40);
    if (result != NULL) {
        printf("Found node with data: %d\n", result->data);
    } else {
        printf("Node not found.\n");
    }

    // Test inorder traversal (recursive)
    printf("Inorder (recursive): ");
    inorderRecursive(root);
    printf("\n");

    // Test inorder traversal (non-recursive)
    printf("Inorder (non-recursive): ");
    inorderNonRecursive(root);
    printf("\n");

    // Test preorder traversal (recursive)
    printf("Preorder (recursive): ");
    preorderRecursive(root);
    printf("\n");

    // Test preorder traversal (non-recursive)
    printf("Preorder (non-recursive): ");
    preorderNonRecursive(root);
    printf("\n");

    // Test postorder traversal (recursive)
    printf("Postorder (recursive): ");
    postorderRecursive(root);
    printf("\n");

    // Test postorder traversal (non-recursive)
    printf("Postorder (non-recursive): ");
    postorderNonRecursive(root);
    printf("\n");

    // Test level-order traversal
    printf("Level-order traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    // Test delete
    root = delete(root, 20);
    printf("After deleting 20, inorder (recursive): ");
    inorderRecursive(root);
    printf("\n");

    return 0;
}

