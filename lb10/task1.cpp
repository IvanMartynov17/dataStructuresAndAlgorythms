#include  <iostream>
#include <string>

using namespace std;

int n = 6;
int matrix[100][100];
int INF = 99999999999999;
int dist[100][100];

void dijkstra(int src) {
    bool visited[100];
    for (int i = 0; i < n; i++) {
        dist[src][i] = INF;
        visited[i] = false;
    }
    dist[src][src] = 0;

    for (int step = 0; step < n - 1; step++) {
    int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[src][i] > dist[src][u])) {
                u = i;
            }
        }

        if (dist[src][u] == INF) break;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (matrix[u][v] != 0 && !visited[v]) {
                if (dist[src][u] + matrix[u][v] < dist[src][v]) {
                    dist[src][v] = dist[src][u] + matrix[u][v];
                }
            }
        }
    }
}

void allPairsShortestPath() {
    for (int i = 0; i < n; i++) {
        dijkstra(i);
    }
}

void initGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    int edges[][3] = {
        {0, 2, 2},
        {1, 2, 6},
        {2, 5, 9},
        {1, 3, 4},
        {3, 5, 4},
        {0, 4, 8}
    };
    int edgescount = 6;
    for (int i = 0; i < edgescount; i++) {
        int u, v, w;
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        matrix[u][v] = w;
        matrix[v][u] = w;
    }
}

void printMatrix() {
    cout << "\tMatrix of sum\t " << endl;


    for (int i = 0; i <= n; i++) {
        cout << i + 1<< " ";
        for (int j = 0; j <= n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void isFullGraph() {
    cout << endl;
    cout << "\tIs full graph? " << endl;
    cout << endl;
    bool isFull = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i!=j && matrix[i][j] == 0) {
                isFull = false;
                break;
            }
        }
            if (!isFull) break;
    }
    if (isFull)
    cout << "Graph full. " << endl;
    else {
        cout << "Graph not full. " << endl;
    }
}

void printAdjacencyList() {
    cout << endl;
    cout << "\tAdjacency list" << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Top " << i + 1 << ": ";
        bool hasNeighbors = false;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                cout << j + 1 << " ";
                hasNeighbors = true;
            }
        }
       if (!hasNeighbors) cout << "empty ";
        cout << endl;
    }
}

void avgPathLength() {


    int sum = 0;
    int count = 0;
    int dist[100][100];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dist[i][j] != INF && dist[j][i] > 0) {
                sum += dist[i][j];
                count++;
            }
    if (count > 0) {
        cout << "Average path length: " << (double)sum / count << endl;
    }
    else {
        cout << "Graph is not connected." << endl;
    }
}

void findIsolated() {
    cout << "Isolated vertices:" << endl;
    bool foundIsolated = false;

    for (int i = 0; i < n; i++) {
        int neightborCount = 0;
        int nearestNeighbor = -1;
        int nearestDist = INF;

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                neightborCount++;
                if (matrix[i][j] < nearestDist) {
                    nearestDist = matrix[i][j];
                    nearestNeighbor = j;
                }
            }
        }

        if (neightborCount == 1) {
            cout << "Isolated vertex: " << i + 1 << " "
            << nearestNeighbor + 1 << " " << nearestDist
            << endl;
            foundIsolated = true;
        }
    }
    if (!foundIsolated) cout << "No isolated vertices." << endl;

    bool foundFull = false;
    for ( int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) cnt++;
        }
        if (cnt == 0) {
            cout << "Full vertex: " << i + 1 << endl;
            foundFull = true;
        }
    }
    if (!foundFull) cout << "No full vertices." << endl;

}

int main()
        {
    initGraph();
    printMatrix();
    isFullGraph();
    printAdjacencyList();
    allPairsShortestPath();
    avgPathLength();

    return 0;
}