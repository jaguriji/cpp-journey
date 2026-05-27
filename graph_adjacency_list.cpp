#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Graph {
    int vertices;
    Node* adjList[10];

    void addToList(Node*& head, int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

public:
    Graph(int v) {
        vertices = v;
        for(int i = 0; i < v; i++) adjList[i] = NULL;
    }

    void addEdge(int u, int v) {
        addToList(adjList[u], v);
        addToList(adjList[v], u);
    }

    void display() {
        cout << "Adjacency List:" << endl;
        for(int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            Node* temp = adjList[i];
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void bfs(int start) {
        bool visited[10] = {false};
        int queue[10];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "BFS: ";
        while(front < rear) {
            int node = queue[front++];
            cout << node << " ";
            Node* temp = adjList[node];
            while(temp) {
                if(!visited[temp->data]) {
                    visited[temp->data] = true;
                    queue[rear++] = temp->data;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void dfsHelper(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";
        Node* temp = adjList[node];
        while(temp) {
            if(!visited[temp->data])
                dfsHelper(temp->data, visited);
            temp = temp->next;
        }
    }

    void dfs(int start) {
        bool visited[10] = {false};
        cout << "DFS: ";
        dfsHelper(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.display();
    cout << endl;
    g.bfs(0);
    g.dfs(0);

    return 0;
}