#include <stdio.h>
#define MAX 1000
int graph[MAX][MAX];

int main(){
    int V, E, K, R;

    int owner[MAX];
    int distance[MAX];
    int queue[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V <= 0 || V > MAX || E < 0){
        printf("Invalid graph size.\n");
        return 0;
    }

    // Initially, there are no edges
    for (int i = 0; i < V; i++){
        owner[i] = -1;
        distance[i] = -1;
    }

    printf("Enter undirected edges:\n");

    for (int i = 0; i < E; i++){
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= V || v < 0 || v >= V){
            printf("Invalid edge.\n");
            return 0;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter number of service hubs: ");
    scanf("%d", &K);

    if (K <= 0 || K > V){
        printf("Invalid number of hubs.\n");
        return 0;
    }

    int hubs[MAX] = {0};

    printf("Enter hub vertices in order:\n");

    for (int i = 0; i < K; i++){
        int h;
        scanf("%d", &h);

        if (h < 0 || h >= V || hubs[h]){
            printf("Invalid or duplicate hub.\n");
            return 0;
        }

        hubs[h] = 1;

        // Each hub gets its own index
        owner[h] = i + 1;
        distance[h] = 0;
    }

    printf("Enter radius R: ");
    scanf("%d", &R);

    if (R < 0){
        printf("Invalid radius.\n");
        return 0;
    }

    int front = 0, rear = 0;

    // Add all hubs to the queue
    for (int i = 0; i < V; i++){
        if (hubs[i])
            queue[rear++] = i;
    }

    // Multi-source BFS
    while (front < rear){
        // Process one complete distance level
        int levelEnd = rear;

        while (front < levelEnd){
            int u = queue[front++];

            for (int v = 0; v < V; v++){
                if (graph[u][v] == 1){
                    if (distance[v] == -1){
                        distance[v] = distance[u] + 1;
                        owner[v] = owner[u];

                        queue[rear++] = v;
                    }
                    else if (distance[v] == distance[u] + 1){
                        // Choose smaller hub index in a tie
                        if (owner[u] < owner[v])
                            owner[v] = owner[u];
                    }
                }
            }
        }
    }

    printf("\nVertex\tOwner\tDistance\n");

    for (int i = 0; i < V; i++){
        if (distance[i] == -1 || distance[i] > R)
            printf("%d\t-1\t-1\n", i);
        else
            printf("%d\t%d\t%d\n",
                   i, owner[i], distance[i]);
    }

    return 0;
}