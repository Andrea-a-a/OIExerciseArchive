//B3647 ¡¾Ä£°å¡¿Floyd
#include <iostream>
#include <cstring>

using namespace std;
int m, n;
int a[101][101];
int dp[101][101];

void floyd(int n){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)  {dp[i][i] = 0; }
                else dp[i][j] = min(dp[i][k]+dp[k][j], dp[i][j]);

            }

        }

    }

}





int main(){
    memset(dp, 0x3f, sizeof(dp));
    freopen("test.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int o, p;
        cin >> o >>p >> dp[o][p];
        dp[p][o] = dp[o][p];
    }
    floyd(n);
    for(int i = 1; i <= n; i++){
        for(int o = 1; o <= n; o++){
            cout << dp[i][o] <<" ";
        }
        cout << endl;
    }
    return 0;


}
