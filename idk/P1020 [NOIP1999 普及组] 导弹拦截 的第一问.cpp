//P1020 [NOIP1999 普及组] 导弹拦截
//只做第一问>< 应该使用优化的LIS？
//不知道 抄抄试试 
#include <iostream>
using namespace std;

int a[10010], dp[10010], temp;


int main(){
	int p = 0;
//	do{
//		p++;
//	}while(cin >> a[p]);
	while(cin >> temp)	a[++p] = temp;
	cout << 1;
	int ans = -1111111;
	for(int i = 0; i < p+1; i++){
		dp[i] = 1;
		for(int o = 0; o < i; o++){
			if(a[o]<a[i])	dp[i] = max(dp[i], dp[o]+1);
		}
		ans = max(ans, dp[i]);
	}
	//int ans = -1111111;
	
	cout << ans;
	return 0;
} 
