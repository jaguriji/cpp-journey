#include<iostream>
using namespace std;

#define INF 99999
#define V 4

void printMatrix(int dist[][V]) {
    cout << "Shortest distances:" << endl;
    cout << "\t";
    for(int i = 0; i < V; i++) cout << i << "\t";
    cout << endl;
    for(int i = 0; i < V; i++) {
        cout << i << "\t";
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == INF) cout << "INF\t";
            else cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V];
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF &&
                   dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // check negative cycle
    bool negCycle = false;
    for(int i = 0; i < V; i++)
        if(dist[i][i] < 0) { negCycle = true; break; }

    if(negCycle) { cout << "Negative cycle detected!" << endl; return; }

    printMatrix(dist);
}

int main() {
    int graph[V][V] = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    cout << "--- Original Graph ---" << endl;
    printMatrix(graph);
    cout << "\n--- After Floyd Warshall ---" << endl;
    floydWarshall(graph);

    cout << "\n--- Example 2 ---" << endl;
    int g2[V][V] = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };
    floydWarshall(g2);

    return 0;
}