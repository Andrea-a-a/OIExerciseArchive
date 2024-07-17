//P1164 小A点菜
//好像事背包又好像不是 不确定 再看看 
//进行一个题解的抄！
#include <iostream>
using namespace std;
int n, m, a[105];
int dp[105][10010] = {0};

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(j == a[i])	dp[i][j] = dp[i-1][j] + 1;
			else if(j > a[i])	dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i]];
			else if(j < a[i])	dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n][m];
	return 0;
}
//睡觉 明天再想想用背包怎么写（感觉会长欸 
