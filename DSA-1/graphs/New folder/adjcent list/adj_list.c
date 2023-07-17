#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Node
{
    int vertex;
    struct Node* next;
} Node;

// Function to add a node to the adjacency list
void addNode(Node** adjList, int src, int dest)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Function to create the adjacency list from the adjacency matrix
void createAdjList(int adjMatrix[][MAX_VERTICES], int numVertices, Node** adjList)
{
    int i, j;

    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                addNode(adjList, i, j);
            }
        }
    }
}

// Function to save the adjacency list to a file
void saveAdjListToFile(Node** adjList, int numVertices, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%d\n", numVertices);

    for (int i = 0; i < numVertices; i++)
    {
        fprintf(file, "%d -> ", i);
        Node* current = adjList[i];
        while (current != NULL)
        {
            fprintf(file, "%d ", current->vertex);
            current = current->next;
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Adjacency list saved to %s successfully.\n", filename);
}

int main()
{
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    Node* adjList[MAX_VERTICES];
    int numVertices;

    // Read the adjacency matrix from a file
    FILE* file = fopen("graph.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }

    fscanf(file, "%d", &numVertices);

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            fscanf(file, "%d", &adjMatrix[i][j]);
        }
    }

    fclose(file);

    // Create the adjacency list from the adjacency matrix
    for (int i = 0; i < numVertices; i++)
    {
        adjList[i] = NULL;
    }

    createAdjList(adjMatrix, numVertices, adjList);

    // Save the adjacency list to a file
    saveAdjListToFile(adjList, numVertices, "adjacency_list.txt");

    return 0;
}
