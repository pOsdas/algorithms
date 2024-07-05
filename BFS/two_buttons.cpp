#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;

    while (n < m) {
        if (m % 2 == 0) {
            m /= 2;
        }
        else {
            m++;
        }
        count++;
    }

    count += n - m;

    cout << count << endl;

    return 0;
}
