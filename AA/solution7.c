#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void insertEdge(Graph *graph, int source, int destination) {
    if (source >= 0 && source < graph->numNodes && destination >= 0 && destination < graph->numNodes) {
        graph->matrix[source][destination] = 1;
        graph->matrix[destination][source] = 1; // Assuming an undirected graph
    } else {
        return;
    }
}

void deleteEdge(Graph *graph, int source, int destination) {
    if (source >= 0 && source < graph->numNodes && destination >= 0 && destination < graph->numNodes) {
        graph->matrix[source][destination] = 0;
        graph->matrix[destination][source] = 0; // Assuming an undirected graph
    } else {
        return;
    }
}

void deleteNode(Graph *graph, int node) {
    int i, j;
    if (node >= 0 && node < graph->numNodes) {
        for (i = node; i < graph->numNodes - 1; i++) {
            for (j = 0; j < graph->numNodes; j++) {
                graph->matrix[i][j] = graph->matrix[i + 1][j];
            }
        }
        for (i = 0; i < graph->numNodes; i++) {
            for (j = node; j < graph->numNodes - 1; j++) {
                graph->matrix[i][j] = graph->matrix[i][j + 1];
            }
        }
        graph->numNodes--;
    } else {
        return;
    }
}

void DFSUtil(Graph *graph, int node, int visited[]) {
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->matrix[node][i] != 0 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph *graph, int startNode) {
    int visited[MAX_NODES];
    for (int i = 0; i < graph->numNodes; i++) {
        visited[i] = 0;
    }
    DFSUtil(graph, startNode, visited);
    printf("\n");
}

void BFS(Graph *graph, int startNode) {
    int visited[MAX_NODES];
    for (int i = 0; i < graph->numNodes; i++) {
        visited[i] = 0;
    }

    int queue[MAX_NODES];
    int front = -1, rear = -1;
    queue[++rear] = startNode;
    visited[startNode] = 1;

    while (front != rear) {
        int currentNode = queue[++front];
        printf("%d ", currentNode);
        for (int i = 0; i < graph->numNodes; i++) {
            if (graph->matrix[currentNode][i] != 0 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// TODO: debug Dijkstra
void dijkstra(Graph *graph, int startNode) {
    int distance[MAX_NODES];
    int visited[MAX_NODES];
    int i, j, minDistance, nextNode;

    for (i = 0; i < graph->numNodes; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[startNode] = 0;

    for (i = 0; i < graph->numNodes - 1; i++) {
        minDistance = INT_MAX;

        for (j = 0; j < graph->numNodes; j++) {
            if (distance[j] < minDistance) {
                minDistance = distance[j];
                nextNode = j;
            }
        }
        
        visited[nextNode] = 1;

        for (j = 0; j < graph->numNodes; j++) {
            if (graph->matrix[nextNode][j] != 0 &&
                distance[nextNode] + graph->matrix[nextNode][j] < distance[j]) {
                distance[j] = distance[nextNode] + graph->matrix[nextNode][j];
            }
        }
    }

    printf("Shortest distances from node %d:\n", startNode);
    for (i = 0; i < graph->numNodes; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }
}

// TODO: Find shortest route in a graph using dijkstra you can halve the weight of an arbitrary edge along the way only once.
void modified_dijkstra(Graph *graph, int startNode) {
     int distance[MAX_NODES];
    int visited[MAX_NODES];
    int i, j, minDistance, nextNode;

    for (i = 0; i < graph->numNodes; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[startNode] = 0;

    for (i = 0; i < graph->numNodes - 1; i++) {
        minDistance = INT_MAX;

        for (j = 0; j < graph->numNodes; j++) {
            if (distance[j] < minDistance && !visited[j]) {
                minDistance = distance[j];
                nextNode = j;
            }
        }

        visited[nextNode] = 1;

        for (j = 0; j < graph->numNodes; j++) {
            if (graph->matrix[nextNode][j] != 0 && !visited[j]) {
                int weight = graph->matrix[nextNode][j];
                if (distance[nextNode] + weight < distance[j]) {
                    distance[j] = min(distance[nextNode] + weight / 2, distance[j]);
                }
            }
        }
    }

    printf("Shortest distances from node %d: without using the ticket\n", startNode);
    for (i = 0; i < graph->numNodes; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }

    for (i = 0; i < graph->numNodes; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[startNode] = 0;

    for (i = 0; i < graph->numNodes - 1; i++) {
        minDistance = INT_MAX;

        for (j = 0; j < graph->numNodes; j++) {
            if (distance[j] < minDistance && !visited[j]) {
                minDistance = distance[j];
                nextNode = j;
            }
        }

        visited[nextNode] = 1;

        for (j = 0; j < graph->numNodes; j++) {
            if (graph->matrix[nextNode][j] != 0 && !visited[j]) {
                int weight = graph->matrix[nextNode][j];
                if (distance[nextNode] + weight < distance[j]) {
                    distance[j] = min(distance[nextNode] + weight / 2, distance[j]);
                }
            }
        }
    }

    printf("Shortest distances from node %d: by using the ticket\n", startNode);
    for (i = 0; i < graph->numNodes; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }

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
            case 7:
                scanf("%d", &node1);
                dijkstra(&graph, node1);
                break;
            case 8:
                scanf("%d", &node1);
                modified_dijkstra(&graph, node1);
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
case= Dijkstra
input=0 4 0 0 0 0
4 0 3 0 11 0
0 3 0 3 0 0
0 0 3 0 2 0
0 11 0 2 0 0
0 0 0 0 0 0
7 0
0

output=
Result:
Shortest distances from node 0:
Node 0: 0
Node 1: 4
Node 2: 7
Node 3: 10
Node 4: 12
Node 5: 2147483647


case= Ticket Dijkstra
input=0 4 0 0 0 0
4 0 3 0 11 0
0 3 0 3 0 0
0 0 3 0 2 0
0 11 0 2 0 0
0 0 0 0 0 0
8 0
0

output=
Result:
Shortest distances from node 0: without using the ticket
Node 0: 0
Node 1: 4
Node 2: 7
Node 3: 10
Node 4: 12
Node 5: 2147483647
Shortest distances from node 0: by using the ticket
Node 0: 0
Node 1: 2
Node 2: 5
Node 3: 8
Node 4: 9
Node 5: 2147483647
*/
