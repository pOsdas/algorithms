#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v + 1);

    for (int i = 0; i < graph[v].size(); ++i) {
        int neighbor = graph[v][i];

        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, component);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char edge;
            cin >> edge;
            if (edge == '1') {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, graph, visited, component);
            components.push_back(component);
        }
    }

    cout << components.size() << endl;

    for (const auto& component : components) {
        cout << component.size() << endl;
        for (const auto& vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
