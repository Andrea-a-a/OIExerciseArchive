//T348565 [yLOI2022] 长安幻世绘
//感觉dp 不确定 先输进来看吧(距离比赛结束还有38min
#include <iostream>
using namespace std;

int n, m;
int a[10010];
//bool used[10010] = {0};
//int dp[10010][10010];
int minn, minm = 0x3f3f3f3f, maxm = -1e9, cnt = 1;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for(int i = 1; i <= n; i+2){
		minm = min(minm, a[i]);
		maxm = max(maxm, a[i]); 
		cnt++;
	}
	minn = maxm - minm;
	cout << minn;
//	for(int i = 1; i <= n; i++){
//		
//		}
//		
//	}
//	minm = maxm = a[0];
//	used[0] = 1;
//	cnt = 1;
//	for(int o = 2;cnt <= m; o++){
//			if(a[o] <= maxm && a[o] >= minm && used[o-1] == 0){
//				minm = min(minm, a[o]);
//				maxm = max(maxm, a[o]);
//				if(cnt >= 2)	minn = min(minn, maxm - minm);
//				used[o] = 1;
//				cnt++;
//			}
//	}
	//cout  << minn;
	return 0;
	
} 
