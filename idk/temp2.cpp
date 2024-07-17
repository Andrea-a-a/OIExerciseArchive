#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int g[210][210];

void floyd(int n);

int main() {
    int n;
    memset(g, INF, sizeof(g));
    cin >> n;
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
        for (int j = i + 1; j < n; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }
    floyd(n);
    cout << g[0][n - 1] << endl;
    return 0;
}

void floyd(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

