//P1048 [NOIP2005 普及组] 采药
//01背包 总之就是抄ppt！好困哦
#include <iostream>
//#include "string.h"
using namespace std;
int T, M;
int c[110], w[110], dp[11000];

int main(){
	//memset(dp, -1, sizeof(dp));
	cin >> T >> M;
	for(int i = 0; i < M; i++){
		cin >> c[i] >> w[i];
	}
	for(int i = 0; i < M; i++){
		for(int j = T; j >= c[i]; j--){
			dp[j] = max(dp[j-c[i]] + w[i], dp[j]);
		}
	}
	cout << dp[T] <<endl;
	return 0;
	
} 
