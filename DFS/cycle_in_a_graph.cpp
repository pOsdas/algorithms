#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasCycleUtil(int v, vector<vector<int>>& graph, vector<bool>& visited, int parent, unordered_set<int>& cycleVertices) {
    visited[v] = true;

    for (int i = 0; i < graph[v].size(); ++i) {
        int neighbor = graph[v][i];

        if (!visited[neighbor]) {
            if (hasCycleUtil(neighbor, graph, visited, v, cycleVertices)) {
                cycleVertices.insert(v);
                return true;
            }
        }
        else if (neighbor != parent) {
            cycleVertices.insert(neighbor);
            cycleVertices.insert(v);
            return true;
        }
    }

    return false;
}

bool hasCycle(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    unordered_set<int> cycleVertices;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (hasCycleUtil(i, graph, visited, -1, cycleVertices)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    if (hasCycle(graph, n)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
