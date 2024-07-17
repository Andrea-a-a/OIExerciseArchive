//P1757 通天之分组背包
//据说叫分组背包 不太会 不确定 再看看

#include <iostream>
using namespace std;
int T, M, x, t;
int c[1010], w[1010], dp[1100], b[101], g[110][110];

int main(){
	cin >> T >> M;
	for(int i = 0; i < M; i++){
		cin >> w[i] >> c[i] >> x;
		t = max(t, x);
		
		g[x][b[x]] = i;
		b[x]++;
	}
	for(int i = 1; i <= t; i++){
		for(int j = T; j >= 0; j--){
			for(int k = 0; k < b[i]; k++){
				if(j>=w[g[i][k]])	dp[j] = max(dp[j], dp[j-w[g[i][k]]]+c[g[i][k]]);
			}
		}
	}
	cout << dp[T] <<endl;
	return 0;
	
} 
