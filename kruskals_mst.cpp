#include<iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int parent[10], rank_[10];

int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int px = find(x), py = find(y);
    if(rank_[px] < rank_[py]) parent[px] = py;
    else if(rank_[px] > rank_[py]) parent[py] = px;
    else { parent[py] = px; rank_[px]++; }
}

void sortEdges(Edge edges[], int e) {
    for(int i = 0; i < e-1; i++)
        for(int j = 0; j < e-i-1; j++)
            if(edges[j].weight > edges[j+1].weight)
                swap(edges[j], edges[j+1]);
}

void kruskal(int v, int e, Edge edges[]) {
    for(int i = 0; i < v; i++) { parent[i] = i; rank_[i] = 0; }
    sortEdges(edges, e);

    cout << "Minimum Spanning Tree:" << endl;
    cout << "Edge\t\tWeight" << endl;
    int totalWeight = 0, edgeCount = 0;

    for(int i = 0; i < e && edgeCount < v-1; i++) {
        int u = edges[i].src, w = edges[i].dest;
        if(find(u) != find(w)) {
            cout << u << " - " << w << "\t\t" << edges[i].weight << endl;
            totalWeight += edges[i].weight;
            unionSets(u, w);
            edgeCount++;
        }
    }
    cout << "Total MST weight: " << totalWeight << endl;
}

int main() {
    int v, e;
    cout << "Enter vertices and edges: ";
    cin >> v >> e;
    Edge edges[e];
    cout << "Enter edges (src dest weight):" << endl;
    for(int i = 0; i < e; i++)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    kruskal(v, e, edges);

    cout << "\n--- Example ---" << endl;
    Edge ex[] = {{0,1,4},{0,2,3},{1,2,1},{1,3,2},{2,3,4},{3,4,2},{2,4,5}};
    cout << "Graph with 5 vertices, 7 edges" << endl;
    kruskal(5, 7, ex);

    return 0;
}