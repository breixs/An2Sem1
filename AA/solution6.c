#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 6

typedef struct {
    int matrix[MAX_NODES][MAX_NODES];
    int numNodes;
} Graph;

void initGraph(Graph *graph, int numNodes) {
    int i, j;
    graph->numNodes = numNodes;
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            graph->matrix[i][j] = 0;
        }
    }
}

void printGraph(Graph *graph) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < graph->numNodes; i++) {
        for (j = 0; j < graph->numNodes; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void readGraph(Graph *graph) {
    int i, j;
    for (i = 0; i < graph->numNodes; i++) {
        for (j = 0; j < graph->numNodes; j++) {
            scanf("%d", &graph->matrix[i][j]);
        }
    }
}

void insertNode(Graph *graph, int node) {
    if (node >= 0 && node < MAX_NODES) {
        graph->numNodes++;
    } else {
        printf("Invalid node number.\n");
    }
}

// TODO
void insertEdge(Graph *graph, int source, int destination) {
    if(source>=0&& source < graph->numNodes && destination >=0&&
    destination < graph->numNodes)
    {
        graph->matrix[source][destination]=1;
        graph->matrix[destination][source]=1;
    }
}

// TODO
void deleteEdge(Graph *graph, int source, int destination) {
    if(source>=0&& source < graph->numNodes && destination >=0&&
    destination < graph->numNodes)
    {
        graph->matrix[source][destination]=0;
        graph->matrix[destination][source]=0;
        //printf("%d %d \n", source, destination);
    }
}

// TODO
void deleteNode(Graph *graph, int node) {
    int i;
    if(node>=0&&node<graph->numNodes)   
    {
        for(i=0;i<graph->numNodes;i++)
        {
            graph->matrix[node][i]=0;
            graph->matrix[i][node]=0;
        }

        if(node< graph->numNodes-1)
        {
            for(int i=0;i<graph->numNodes;i++)
            {
                graph->matrix[i][node]=graph->matrix[i][graph->numNodes-1];
                graph->matrix[node][i]=graph->matrix[graph->numNodes-1][i];
            }
        }

        graph->numNodes--;
        //printf("%d",node);
    }
}

// TODO
void DFSUtil(Graph *graph, int node, int visited[]) {
    printf("%d ", node);
    // continue...
    visited[node]=1;

    for(int i=0;i<graph->numNodes;i++)
    {
        if(graph->matrix[node][i]==1 && !visited[i])
        {
            DFSUtil(graph, i, visited);
        }
    }
}

// TODO
void DFS(Graph *graph, int startNode) {
    int visited[MAX_NODES]={0};

    DFSUtil(graph, startNode, visited);

    // at the end print new line
    printf("\n");
}

// TODO
void BFS(Graph *graph, int startNode) {
    int visited[MAX_NODES]={0};
    int q[MAX_NODES];
    int front=-1, rear=-1;
    int i;

    q[++rear]=startNode;
    visited[startNode]=1;

    while(front != rear)
    {
        int currentNode=q[++front];
        printf("%d ", currentNode);

        for(i=0;i<graph->numNodes;i++)
        {
            if(graph->matrix[currentNode][i]==1 && !visited[i])
            {
                q[++rear]=i;
                visited[i]=1;
            }
        }
    }

    // at the end print new line
    printf("\n");
}

int main() {
    Graph graph;
    initGraph(&graph, MAX_NODES);
    readGraph(&graph);
    int option, node1, node2;
    printf("Result:\n");

    do {
        // printf("\nMenu:\n");
        // printf("1. Print Graph\n");
        // printf("2. Insert Edge\n");
        // printf("3. Delete Edge\n");
        // printf("4. Delete Node\n");
        // printf("0. Exit\n");
        // printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printGraph(&graph);
                break;
            case 2:
                scanf("%d %d", &node1, &node2);
                insertEdge(&graph, node1, node2);
                break;
            case 3:
                scanf("%d %d", &node1, &node2);
                deleteEdge(&graph, node1, node2);
                break;
            case 4:
                scanf("%d", &node1);
                deleteNode(&graph, node1);
                break;
            case 5:
                scanf("%d", &node1);
                DFS(&graph, node1);
                break;
            case 6:
                scanf("%d", &node1);
                BFS(&graph, node1);
                break;
            case 0:
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 0);

    return 0;
}

/*

case= Insert Edge
input=0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 0 0
0 0 1 0 1 1
0 0 0 1 0 0
0 0 0 1 0 0
2 4 5
2 4 0
2 10 9
1
0

output=
Adjacency Matrix:
0 1 1 0 1 0 
1 0 1 0 0 0 
1 1 0 1 0 0 
0 0 1 0 1 1 
1 0 0 1 0 1 
0 0 0 1 1 0


case= Delete Edge
input=0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 0 0
0 0 1 0 1 1
0 0 0 1 0 0
0 0 0 1 0 0
3 2 3
3 4 3
3 3 10
1
0

output=
Adjacency Matrix:
0 1 1 0 0 0 
1 0 1 0 0 0 
1 1 0 0 0 0 
0 0 0 0 0 1 
0 0 0 0 0 0 
0 0 0 1 0 0


case= Delete Node
input=0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 0 0
0 0 1 0 1 1
0 0 0 1 0 0
0 0 0 1 0 0
4 5
4 0
4 10
1
0

output=
Adjacency Matrix:
0 1 0 0 
1 0 1 0 
0 1 0 1 
0 0 1 0


case= DFS
input=0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 0 0
0 0 1 0 1 1
0 0 0 1 0 0
0 0 0 1 0 0
5 0
5 5
1
0

output=
0 1 2 3 4 5 
5 3 2 0 1 4 
Adjacency Matrix:
0 1 1 0 0 0 
1 0 1 0 0 0 
1 1 0 1 0 0 
0 0 1 0 1 1 
0 0 0 1 0 0 
0 0 0 1 0 0


case= BFS
input=0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 0 0
0 0 1 0 1 1
0 0 0 1 0 0
0 0 0 1 0 0
6 0
6 2
1
0

output=
0 1 2 3 4 5 
2 0 1 3 4 5 
Adjacency Matrix:
0 1 1 0 0 0 
1 0 1 0 0 0 
1 1 0 1 0 0 
0 0 1 0 1 1 
0 0 0 1 0 0 
0 0 0 1 0 0

*/