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

void postorderTraversal(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left, file);
    postorderTraversal(root->right, file);
    fprintf(file, "%d ", root->data);
}

int main() {
    FILE* inputFile = fopen("binary_tree.txt", "r");
    FILE* postorderFile = fopen("postorder.txt", "w");
    if (inputFile == NULL || postorderFile == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    Node* root = NULL;
    int value;
    while (fscanf(inputFile, "%d", &value) != EOF) {
        root = insertNode(root, value);
    }

    postorderTraversal(root, postorderFile);

    fclose(inputFile);
    fclose(postorderFile);

    printf("Postorder traversal has been saved to the 'postorder.txt' file.\n");

    return 0;
}

