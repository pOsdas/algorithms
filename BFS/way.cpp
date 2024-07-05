#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int shortway(vector<vector<int>>& graph, int begin, int end) {
    int n = graph.size();
    vector<int> dist(n, INF);

    queue<int> q;
    q.push(begin);
    dist[begin] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int neig = 0; neig < n; ++neig) {
            if (graph[cur][neig] == 1 && dist[neig] == INF) {
                dist[neig] = dist[cur] + 1;
                q.push(neig);
            }
        }
    }

    return (dist[end] == INF) ? -1 : dist[end];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int begin, end;
    cin >> begin >> end;

    int ans = shortway(graph, begin - 1, end - 1);

    cout << ans << endl;

    return 0;
}
