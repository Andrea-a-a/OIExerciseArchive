//P1439 【模板】最长公共子序列
//"T4需要用优化的算法，朴素算法可以得到50分" 
#include <iostream>
//#include <cstdio> //scanf
//#include "string.h" //strlen

using namespace std;

int n, a[1010], b[1010];
int dp[1010][1010];

int main(){
	
	//cout << lena;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i+1];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i+1];
	}
	for(int i = 1; i<= n; i++){
		for(int o = 1; o <= n; o++){
			if(a[i] == b[o])	dp[i][o] = dp[i-1][o-1]+1;
			else	dp[i][o] = max(dp[i-1][o], dp[i][o-1]);
		}
	}
	cout << dp[n][n] << endl;
	return 0;
	
} 
