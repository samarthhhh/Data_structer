#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node8* right;
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

void inorderTraversal(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left, file);
    fprintf(file, "%d ", root->data);
    inorderTraversal(root->right, file);
}

int main() {
    FILE* inputFile = fopen("binary_tree.txt", "r");
    FILE* inorderFile = fopen("inorder.txt", "w");
    if (inputFile == NULL || inorderFile == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    Node* root = NULL;
    int value;
    while (fscanf(inputFile, "%d", &value) != EOF) {
        root = insertNode(root, value);
    }

    inorderTraversal(root, inorderFile);

    fclose(inputFile);
    fclose(inorderFile);

    printf("Inorder traversal has been saved to the 'inorder.txt' file.\n");

    return 0;
}

