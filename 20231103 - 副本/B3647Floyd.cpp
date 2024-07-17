//B3647 【模板】Floyd
#include <iostream>
#include <cstring>
// #include <vector>
using namespace std;
int n, m;
int a[110][110];



int main(){
    memset(a, 0x3f, sizeof(a));
   
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v >> a[u][v];
        a[v][u] = a[u][v];
    }
     for(int i = 1; i <= n; i++){a[i][i] = 0;}
    // cout << endl;
    //     for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}