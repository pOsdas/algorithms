#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<int> bfs(vector<vector<int>>& graph, int start, int end) {
    vector<int> distance(graph.size(), INF);
    vector<int> parent(graph.size(), -1);
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to = 0; to < graph.size(); ++to) {
            if (graph[v][to] == 1 && distance[to] == INF) {
                distance[to] = distance[v] + 1;
                parent[to] = v;
                q.push(to);
            }
        }
    }
    return parent;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            graph[i][j] = row[j] - '0';
        }
    }

    int start, end;
    cin >> start >> end;
    start--, end--;

    vector<int> parent = bfs(graph, start, end);

    if (parent[end] == -1) {
        cout << "-1" << endl;
    }
    else {
        vector<int> path;
        for (int v = end; v != -1; v = parent[v]) {
            path.push_back(v + 1);
        }

        cout << path.size() - 1 << endl;
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
