//P1049 [NOIP2001 普及组] 装箱问题
//01背包 让我看看怎么做?? 
#include <iostream>
using namespace std;
int T, M;
int c[110], dp[21000];

int main(){
	//memset(dp, -1, sizeof(dp));
	cin >> T >> M;
	for(int i = 0; i < M; i++){
		cin >> c[i];
	}
	for(int i = 0; i < M; i++){
		for(int j = T; j >= c[i]; j--){
			dp[j] = max(dp[j-c[i]] + c[i], dp[j]);
		}
	}
	cout << T-dp[T] <<endl;
	return 0;
	
} 
