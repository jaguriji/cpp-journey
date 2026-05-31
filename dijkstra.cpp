#include<iostream>
using namespace std;

#define V 6
#define INF 99999

int minDistance(int dist[], bool visited[]) {
    int min = INF, minIdx = -1;
    for(int v = 0; v < V; v++)
        if(!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIdx = v;
        }
    return minIdx;
}

void printPath(int parent[], int j) {
    if(parent[j] == -1) { cout << j; return; }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void dijkstra(int graph[][V], int src) {
    int dist[V];
    bool visited[V];
    int parent[V];

    for(int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0;

    for(int count = 0; count < V-1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for(int v = 0; v < V; v++) {
            if(!visited[v] && graph[u][v] && dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Shortest paths from vertex " << src << ":" << endl;
    cout << "Vertex\tDistance\tPath" << endl;
    for(int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 2},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 2, 14, 10, 0}
    };

    dijkstra(graph, 0);

    cout << "\n--- Example 2 ---" << endl;
    int g2[V][V] = {
        {0, 1, 4, 0, 0, 0},
        {1, 0, 4, 2, 7, 0},
        {4, 4, 0, 3, 5, 0},
        {0, 2, 3, 0, 4, 6},
        {0, 7, 5, 4, 0, 7},
        {0, 0, 0, 6, 7, 0}
    };
    dijkstra(g2, 0);

    return 0;
}