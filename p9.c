#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *newNodeCreate(int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to search a node
struct Node *searchNode(struct Node *root, int target) {
    if (root == NULL || root->key == target)
        return root;

    if (root->key < target)
        return searchNode(root->right, target);

    return searchNode(root->left, target);
}

// Function to insert a node
struct Node *insertNode(struct Node *node, int value) {
    if (node == NULL)
        return newNodeCreate(value);

    if (value < node->key)
        node->left = insertNode(node->left, value);
    else if (value > node->key)
        node->right = insertNode(node->right, value);

    return node;
}

// Post-order traversal
void postOrder(struct Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

// In-order traversal
void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

// Pre-order traversal
void preOrder(struct Node *root) {
    if (root != NULL) {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Find minimum value node
struct Node *findMin(struct Node *root) {
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return findMin(root->left);

    return root;
}

// Delete a node
struct Node *deleteNode(struct Node *root, int x) {
    if (root == NULL)
        return NULL;

    if (x > root->key)
        root->right = deleteNode(root->right, x);
    else if (x < root->key)
        root->left = deleteNode(root->left, x);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL || root->right == NULL) {
            struct Node *temp;
            if (root->left == NULL)
                temp = root->right;
            else
                temp = root->left;

            free(root);
            return temp;
        }
        // Case 3: Two children
        else {
            struct Node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

// Main function
int main() {
    struct Node *root = NULL;

    // Insert nodes
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Search
    if (searchNode(root, 60) != NULL)
        printf("60 found");
    else
        printf("60 not found");

    printf("\n");

    // Traversals
    postOrder(root);
    printf("\n");

    preOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    // Delete node
    root = deleteNode(root, 70);

    printf("After Delete:\n");
    inOrder(root);

    return 0;
}