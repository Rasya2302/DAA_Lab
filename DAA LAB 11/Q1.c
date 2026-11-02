#include <stdio.h>

#define MAX 1000
#define INF 1000000000

// Each edge stores destination and weight
struct Edge{
    int to;
    int weight;
    int next;
};

struct Edge edges[MAX * MAX];
int head[MAX];
int edgeCount = 0;

// Add a directed edge
void addEdge(int u, int v, int w){
    edges[edgeCount].to = v;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[u];

    head[u] = edgeCount;
    edgeCount++;
}

// Simple deque for 0-1 BFS
int deque[2 * MAX * 2];
int front = 2 * MAX;
int rear = 2 * MAX;

// Insert at front
void pushFront(int x){
    deque[--front] = x;
}

// Insert at rear
void pushBack(int x){
    deque[rear++] = x;
}

// Remove from front
int popFront(){
    return deque[front++];
}

// 0-1 BFS
void zeroOneBFS(int V, int source, int dist[][2]){
    for (int i = 0; i < V; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[source][0] = 0;

    pushFront(source * 2);

    while (front < rear){
        int state = popFront();

        int u = state / 2;
        int parity = state % 2;

        for (int i = head[u]; i != -1; i = edges[i].next){
            int v = edges[i].to;
            int w = edges[i].weight;

            int newParity = parity ^ w;
            int newDistance = dist[u][parity] + w;

            if (newDistance < dist[v][newParity]){
                dist[v][newParity] = newDistance;

                int newState = v * 2 + newParity;

                if (w == 0)
                    pushFront(newState);
                else
                    pushBack(newState);
            }
        }
    }
}

int main(){
    int V, E, S, C;
    int dist[MAX][2];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V <= 0 || V > MAX || E < 0 ||
        E > MAX * MAX){
        printf("Invalid graph size.\n");
        return 0;
    }

    for (int i = 0; i < V; i++)
        head[i] = -1;

    printf("Enter directed edges (u v weight):\n");

    for (int i = 0; i < E; i++){
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        if (u < 0 || u >= V || v < 0 ||
            v >= V || (w != 0 && w != 1)){
            printf("Invalid edge.\n");
            return 0;
        }

        addEdge(u, v, w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &S);

    printf("Enter penalty cost C: ");
    scanf("%d", &C);

    if (S < 0 || S >= V || C < 0){
        printf("Invalid source or penalty.\n");
        return 0;
    }

    zeroOneBFS(V, S, dist);

    printf("\nMinimum effective costs:\n");

    for (int i = 0; i < V; i++){
        int evenCost = dist[i][0];
        int oddCost = dist[i][1];

        if (oddCost != INF)
            oddCost += C;

        int answer = (evenCost < oddCost)
                     ? evenCost : oddCost;

        if (answer == INF)
            printf("Vertex %d: Unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, answer);
    }

    return 0;
}