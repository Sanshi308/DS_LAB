Q1.A graph G is defined as a pair (V, E) where V is a set of nodes/vertices and E is a set of edges connecting
pairs of vertices. Graphs may be directed or undirected and may have weighted or unweighted edges.
They can be represented using an adjacency matrix, adjacency list, or edge list.
Write a program to implement the following graph algorithms:
1. Breadth First Search (BFS)
2. Depth First Search (DFS)
3. Minimum Spanning Tree (Kruskal and Prim)
4. Dijkstra's Shortest Path Algorithm
Following are just dry runs (logic understand):

// BFS
#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

void BFS(int graph[MAX][MAX], int n, int start) {
    bool visited[MAX] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}




//DFS
void DFS(int graph[MAX][MAX], int n, int start, bool visited[]) {
    cout << start << " ";
    visited[start] = true;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] && !visited[i]) {
            DFS(graph, n, i, visited);
        }
    }
}



int main() {
    int graph[MAX][MAX] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };

    int n = 4;
    bool visited[MAX] = {false};

    BFS(graph, n, 0);
    cout << endl;

    cout << "DFS Traversal: ";
    DFS(graph, n, 0, visited);

    return 0;
}









//MST
struct Edge {
    int src, dest, weight;
};

int parent[10];

// Find parent
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union sets
void unionSet(int a, int b) {
    parent[a] = b;
}

void kruskal(Edge edges[], int V, int E) {
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight (simple bubble sort)
    for (int i = 0; i < E - 1; i++)
        for (int j = i + 1; j < E; j++)
            if (edges[i].weight > edges[j].weight)
                swap(edges[i], edges[j]);

    cout << "Edges in MST (Kruskal):\n";
    int count = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int a = find(edges[i].src);
        int b = find(edges[i].dest);

        if (a != b) {
            cout << edges[i].src << " - " << edges[i].dest << " : " << edges[i].weight << endl;
            unionSet(a, b);
            count++;
        }
    }
}

Edge edges[] = {
    {0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}
};
kruskal(edges, 4, 5);



//prims:
#include <climits>

void prim(int graph[MAX][MAX], int V) {
    int parent[MAX], key[MAX];
    bool visited[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!visited[i] && (u == -1 || key[i] < key[u]))
                u = i;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST (Prim):\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " : " << graph[parent[i]][i] << endl;
}
int graph[MAX][MAX] = {
    {0,2,0,6,0},
    {2,0,3,8,5},
    {0,3,0,0,7},
    {6,8,0,0,9},
    {0,5,7,9,0}
};
prim(graph, 5);








//Dijikstra
void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "To " << i << " = " << dist[i] << endl;
}






//
