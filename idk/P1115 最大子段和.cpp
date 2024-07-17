//P1115 最大子段和
//进行一个前缀和的求 其实就是抄ppt（
#include <iostream>
using namespace std;

int n, a;
long long sum[200020];
long long minsum = 0;
long long ans = -2147483647;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(i == 0)	sum[i] = a;
		else sum[i] = sum[i-1] + a;
	}
	for(int i = 0; i < n; i++){
		ans = max(ans, sum[i]-minsum);
		minsum = min(minsum, sum[i]);
	}
	cout << ans;
	return 0;
	
	
}

