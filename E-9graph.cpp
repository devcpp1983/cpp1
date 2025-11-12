#include <iostream>
using namespace std;

const int MAX = 10;
int graph[MAX][MAX]; // Adjacency matrix
bool visited[MAX];   // Visited array for DFS

// Recursive DFS function
void DFS(int node, int n) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] != 0 && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n; // Number of cities
    cout << "Enter number of cities: ";
    cin >> n;

    // Initialize graph to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    int flights;
    cout << "Enter number of flights: ";
    cin >> flights;

    cout << "Enter flight details (source destination cost):\n";
    for (int i = 0; i < flights; i++) {
        int src, dest, cost;
        cin >> src >> dest >> cost;

        graph[src][dest] = cost;
        graph[dest][src] = cost; // Assuming bidirectional flights
    }

    // Print adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    // Initialize visited array to false
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // Start DFS from node 0
    DFS(0, n);

    // Check if all cities were visited
    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (connected)
        cout << "\nThe graph is CONNECTED.\n";
    else
        cout << "\nThe graph is NOT CONNECTED.\n";

    return 0;
}
