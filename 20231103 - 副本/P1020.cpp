//P1020 [NOIP1999 普及组] 导弹拦截
//只做第一问>< 应该使用优化的LIS？
//不知道 抄抄试试 
#include <iostream>
#include <algorithm> 
using namespace std;

int a[100100], dp[100010], temp;


int main(){
	//freopen("test.txt", "r", stdin); 
	int p = 0;
	
	/*int n;
	cin >>n ;
	for(int i = 1; i<= n; i++)	cin >> a[i];*/
	
	
	while(cin >> temp)	a[++p] = temp;
	//cout << "miao?"<<a[1]<<endl;
	int ans = -1111111; int len;
	/*for(int i = 0; i < p+1; i++){
		dp[i] = 1;
		for(int o = 0; o < i; o++){
			if(a[o]<a[i])	dp[i] = max(dp[i], dp[o]+1);
		}
		ans = max(ans, dp[i]);
	}*/
	
	for(int i = 1; i <= p; i++){
		len = upper_bound(dp+1,dp+ans+1, a[i],greater<int>()) - dp - 1;
		//cout << len;
		//len = len - dp - 1;
		dp[len+1] = a[i];
		ans = max(ans, len+1);
		//cout << len<<endl;
	}
	
	
	//int ans = -1111111;
	
	cout << ans<<endl;
	ans = -1111111;
		for(int i = 1; i <= p; i++){
		len = lower_bound(dp+1,dp+ans+1, a[i]) - dp - 1;
		//cout << len;
		//len = len - dp - 1;
		dp[len+1] = a[i];
		ans = max(ans, len+1);
		//cout << len<<endl;
	}
	cout << ans;
	return 0;
} 
