//P1387
/*在一个n×m 的只包含 0 和 1 的矩阵里找出一个不包含 0 的最大正方形，输出边长。
输入格式
输入文件第一行为两个整数 n,m(1≤n,m≤100)，接下来 n 行，每行 m 个数字，用空格隔开，0 或 1。
输出格式
一个整数，最大正方形的边长。*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int a[MAXN][MAXN];
int dp[MAXN][MAXN]; //dp，以[i][j]为右下角的正方形的最大边长
int n, m;
int ans = 1;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int o = 1; o <= m; o++){
            cin >> a[i][o];
            if(a[i][o] == 1)    dp[i][o] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int o = 1; o <= m; o++){
            if(a[i][o] == 1) dp[i][o] = min(min(dp[i-1][o-1], dp[i-1][o]), dp[i][o-1])+1;
            ans = max(ans, dp[i][o]);
        }
    }

    cout << ans;
    
    return 0;
}