//P1091 [NOIP2004 提高组] 合唱队形
//从左到右求最大上升子序列LIS  再从右向左 最后枚举最高点 其实就是抄课件（
#include <iostream>
using namespace std;

int n, a[110], lr[110], rl[110];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	
	for(int i = 0; i < n; i++){
		lr[i] = 1;
		for(int o = 0; o < i; o++){
			if(a[o]<a[i])	lr[i] = max(lr[i], lr[o]+1);
		}
	}
	for(int i = n-1; i >= 0; i--){
		rl[i] = 1;
		for(int o = n-1; o > i; o--){
			if(a[o]<a[i])	rl[i] = max(rl[i], rl[o]+1);
		}
	}
	int ans = -1111111;
	for(int i = 0; i < n; i++){
		ans = max(ans, lr[i]+rl[i]-1);
	}
	cout << n-ans;
	return 0;
} 
