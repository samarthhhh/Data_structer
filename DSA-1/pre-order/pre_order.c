#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    }
    else if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void preorderTraversal(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    fprintf(file, "%d ", root->data);
    preorderTraversal(root->left, file);
    preorderTraversal(root->right, file);
}

int main() {
    FILE* inputFile = fopen("binary_tree.txt", "r");
    FILE* preorderFile = fopen("preorder.txt", "w");
    if (inputFile == NULL || preorderFile == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    Node* root = NULL;
    int value;
    while (fscanf(inputFile, "%d", &value) != EOF) {
        root = insertNode(root, value);
    }

    preorderTraversal(root, preorderFile);

    fclose(inputFile);
    fclose(preorderFile);

    printf("Preorder traversal has been saved to the 'preorder.txt' file.\n");

    return 0;
}

