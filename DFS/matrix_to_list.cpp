#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> adjacencyMatrix(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
