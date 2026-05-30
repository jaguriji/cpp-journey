#include<iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int v, int e, Edge edges[], int src) {
    int dist[v];
    for(int i = 0; i < v; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for(int i = 1; i <= v-1; i++) {
        for(int j = 0; j < e; j++) {
            int u = edges[j].src;
            int w = edges[j].dest;
            int wt = edges[j].weight;
            if(dist[u] != INT_MAX && dist[u] + wt < dist[w])
                dist[w] = dist[u] + wt;
        }
    }

    // check negative cycle
    bool negCycle = false;
    for(int j = 0; j < e; j++) {
        int u = edges[j].src;
        int w = edges[j].dest;
        int wt = edges[j].weight;
        if(dist[u] != INT_MAX && dist[u] + wt < dist[w]) {
            negCycle = true;
            break;
        }
    }

    if(negCycle) {
        cout << "Negative cycle detected!" << endl;
        return;
    }

    cout << "Shortest distances from vertex " << src << ":" << endl;
    for(int i = 0; i < v; i++) {
        cout << "Vertex " << i << ": ";
        if(dist[i] == INT_MAX) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

int main() {
    int v, e;
    cout << "Enter vertices and edges: ";
    cin >> v >> e;
    Edge edges[e];
    cout << "Enter edges (src dest weight):" << endl;
    for(int i = 0; i < e; i++)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    bellmanFord(v, e, edges, src);

    cout << "\n--- Example ---" << endl;
    Edge ex[] = {{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},{3,2,5},{3,1,1},{4,3,-3}};
    cout << "Graph with 5 vertices, 8 edges" << endl;
    bellmanFord(5, 8, ex, 0);

    return 0;
}