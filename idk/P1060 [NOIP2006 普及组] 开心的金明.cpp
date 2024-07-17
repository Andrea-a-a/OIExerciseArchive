//P1060 [NOIP2006 普及组] 开心的金明
//很显然是用p1048改的 
//P1048 [NOIP2005 普及组] 采药
//01背包 总之就是抄ppt！好困哦
#include <iostream>
//#include "string.h"
using namespace std;
int T, M;
int c[110], w[110], temp;
//int dp[30010];
int ans[30010];

int main(){
	//memset(dp, -1, sizeof(dp));
	cin >> T >> M;
	for(int i = 0; i < M; i++){
		cin >> c[i] >> w[i];
		//c[i] = c[i] * temp;
	}
	for(int i = 0; i < M; i++){
		for(int j = T; j >= c[i]; j--){
			if(ans[j-c[i]] + c[i] * w[i] > ans[j]){
				//dp[j] = dp[j-c[i]] + c[i];
				ans[j] = ans[j-c[i]] + c[i] * w[i];
			}
			
			//dp[j] = max(dp[j-c[i]] + c[i], dp[j]);
		}
	}
	cout << ans[T] <<endl;
	return 0;
	
} 
