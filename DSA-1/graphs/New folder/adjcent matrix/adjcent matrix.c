#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Function to create a graph using adjacency matrix
void createGraph(int adjMatrix[][MAX_VERTICES], int numVertices)
{
    int i, j;

    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            printf("Enter the value of edge [%d][%d]: ", i, j);
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}

// Function to save the adjacency matrix to a file
void saveGraphToFile(int adjMatrix[][MAX_VERTICES], int numVertices, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%d\n", numVertices);

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            fprintf(file, "%d ", adjMatrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Graph saved to %s successfully.\n", filename);
}

int main()
{
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    createGraph(adjMatrix, numVertices);

    // Save the adjacency matrix to a file
    saveGraphToFile(adjMatrix, numVertices, "graph.txt");

    return 0;
}
