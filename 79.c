// WAP to create a graph & implement the adjacency list representation of the
// graph. Apply DFS and BFS on the given graph to traverse the created Graph.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adj[20];
int visited[20];
int n;

// Add edge to graph
void addEdge(int u, int v) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Display adjacency list
void display() {
    int i;
    struct Node *temp;

    printf("\nAdjacency List:\n");

    for (i = 0; i < n; i++) {
        printf("%d -> ", i);

        temp = adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Depth First Search
void DFS(int v) {
    struct Node *temp;

    visited[v] = 1;
    printf("%d ", v);

    temp = adj[v];

    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFS(temp->vertex);

        temp = temp->next;
    }
}

// Breadth First Search
void BFS(int start) {
    int queue[20], front = 0, rear = 0;
    struct Node *temp;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        temp = adj[v];

        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }

            temp = temp->next;
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Vertices must be between 1 and 20.\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid vertices. Try again.\n");
            i--;
            continue;
        }

        addEdge(u, v);
    }

    display();

    printf("\nEnter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex.\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    printf("\n");

    return 0;
}
