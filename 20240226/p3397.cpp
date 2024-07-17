#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
int a[MAXN][MAXN];
int sum[MAXN][MAXN];
int m, n;


int main(){
    cin >> n >> m;
    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x2+1][y2+1]++;
        a[x1][y2+1]--;
        a[x2+1][y1]--;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] -sum[i-1][j-1] + a[i][j];
            cout << sum[i][j] << " ";

        }
        cout << endl;
    }



    return 0;
}