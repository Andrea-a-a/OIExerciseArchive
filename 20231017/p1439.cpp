//p1439
//P1439 【模板】最长公共子序列
//"T4需要用优化的算法，朴素算法可以得到50分"
#include <iostream>
//#include <cstdio> //scanf
//#include "string.h" //strlen

using namespace std;

int n, a[101000], b[101000];
int dp[101000];

int main(){

	//cout << lena;
	cin >> n;
	int u,v;
	for(int i = 1; i <= n; i++){
		cin >> u;
		a[u] = i;
	}
	for(int i = 1; i <= n; i++){
		cin >> v;
		b[i] = a[v];
	}
	dp[0] = 0;
	int ans = 0;
	int len;
	for(int i = 1; i <= n; i++){
		len = lower_bound(dp+1,dp+ans+1, b[i]) - dp - 1;
		//cout << len;
		//len = len - dp - 1;
		dp[len+1] = b[i];
		ans = max(ans, len+1);
		//cout << len<<endl;
	}
		/*for(int i=2;i<=n;i++)
	{
		int l=0,r=len,mid;
		if(b[i]>dp[len])dp[++len]=b[i];
		//如果刚好大于末尾，暂时向后顺次填充
		else
		{
		while(l<r)
		{
		    mid=(l+r)/2;
		    if(dp[mid]>b[i])r=mid;
	//如果仍然小于之前所记录的最小末尾，那么不断
	//向前寻找(因为是最长上升子序列，所以f数组必
	//然满足单调)
			else l=mid+1;
		}
		dp[l]=min(b[i],dp[l]);//更新最小末尾
     	}
    }*/



	cout << ans<< endl;
	return 0;

}
