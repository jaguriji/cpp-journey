#include<iostream>
using namespace std;

#define V 5
#define INF 99999

int minKey(int key[], bool mstSet[]) {
    int min = INF, minIdx = -1;
    for(int v = 0; v < V; v++)
        if(!mstSet[v] && key[v] < min) {
            min = key[v];
            minIdx = v;
        }
    return minIdx;
}

void primsMST(int graph[][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }
    key[0] = 0;

    for(int count = 0; count < V-1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    cout << "Edge\t\tWeight" << endl;
    int totalWeight = 0;
    for(int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t\t" << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total MST weight: " << totalWeight << endl;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primsMST(graph);

    cout << "\n--- Example 2 ---" << endl;
    int g2[V][V] = {
        {0, 4, 0, 0, 0},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 2},
        {0, 0, 7, 0, 6},
        {0, 0, 2, 6, 0}
    };
    primsMST(g2);

    return 0;
}