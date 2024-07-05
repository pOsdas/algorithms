#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, S;
    cin >> N >> S;

    vector<vector<int>> adjacencyMatrix(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    vector<bool> visited(N, false);
    queue<int> q;

    q.push(S - 1);
    visited[S - 1] = true;
    int friendCount = 0;

    while (!q.empty()) {
        int currentPerson = q.front();
        q.pop();
        for (int i = 0; i < N; ++i) {
            if (adjacencyMatrix[currentPerson][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
                friendCount++;
            }
        }
    }
    cout << friendCount << endl;

    return 0;
}
