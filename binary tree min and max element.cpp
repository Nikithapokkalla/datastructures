#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *insert(struct Node *node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct Node *search(struct Node *node, int key) {
    if (node == NULL || node->key == key)
        return node;

    if (key < node->key)
        return search(node->left, key);
    
    return search(node->right, key);
}

struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node *maxValueNode(struct Node *node) {
    struct Node *current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int searchKey = 40;
    struct Node *searchResult = search(root, searchKey);
    if (searchResult)
        printf("Element %d found in the tree.\n", searchKey);
    else
        printf("Element %d not found in the tree.\n", searchKey);

    struct Node *minNode = minValueNode(root);
    printf("Minimum element in the tree: %d\n", minNode->key);

    struct Node *maxNode = maxValueNode(root);
    printf("Maximum element in the tree: %d\n", maxNode->key);

    return 0;
}

