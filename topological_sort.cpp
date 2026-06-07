#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Graph {
    int v;
    Node* adjList[10];

    void addToList(Node*& head, int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void dfsHelper(int node, bool visited[], int stack[], int& top) {
        visited[node] = true;
        Node* temp = adjList[node];
        while(temp) {
            if(!visited[temp->data])
                dfsHelper(temp->data, visited, stack, top);
            temp = temp->next;
        }
        stack[++top] = node;
    }

public:
    Graph(int v) {
        this->v = v;
        for(int i = 0; i < v; i++) adjList[i] = NULL;
    }

    void addEdge(int u, int v) { addToList(adjList[u], v); }

    void topoSortDFS() {
        bool visited[10] = {false};
        int stack[10], top = -1;

        for(int i = 0; i < v; i++)
            if(!visited[i])
                dfsHelper(i, visited, stack, top);

        cout << "Topological Sort (DFS): ";
        while(top >= 0) cout << stack[top--] << " ";
        cout << endl;
    }

    void topoSortBFS() {
        int inDegree[10] = {0};
        for(int i = 0; i < v; i++) {
            Node* temp = adjList[i];
            while(temp) { inDegree[temp->data]++; temp = temp->next; }
        }

        int queue[10], front = 0, rear = 0;
        for(int i = 0; i < v; i++)
            if(inDegree[i] == 0) queue[rear++] = i;

        cout << "Topological Sort (BFS/Kahn): ";
        int count = 0;
        while(front < rear) {
            int node = queue[front++];
            cout << node << " ";
            count++;
            Node* temp = adjList[node];
            while(temp) {
                if(--inDegree[temp->data] == 0)
                    queue[rear++] = temp->data;
                temp = temp->next;
            }
        }
        cout << endl;

        if(count != v) cout << "Cycle detected — topological sort not possible" << endl;
    }

    void display() {
        cout << "Graph:" << endl;
        for(int i = 0; i < v; i++) {
            cout << i << " -> ";
            Node* temp = adjList[i];
            while(temp) { cout << temp->data << " "; temp = temp->next; }
            cout << endl;
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.display();
    cout << endl;
    g.topoSortDFS();
    g.topoSortBFS();

    cout << "\n--- Example 2 ---" << endl;
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 3);
    g2.addEdge(2, 3);
    g2.display();
    cout << endl;
    g2.topoSortDFS();
    g2.topoSortBFS();

    return 0;
}