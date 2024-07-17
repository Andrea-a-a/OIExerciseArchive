//P1435 [IOI2000] 回文字串
//最大公共子序列 LCS 总之依然是抄ppt（ 
#include <iostream>
#include <cstdio> //scanf
#include "string.h" //strlen

using namespace std;

char a[1010], b[1010];
int dp[1010][1010];

int main(){
	scanf("%s", a+1);
	int len = strlen(a+1);
	//cout << lena;
	for(int i = 1; i <= len; i++){
		b[len-i+1] = a[i];
	}
	for(int i = 1; i<= len; i++){
		for(int o = 1; o <= len; o++){
			if(a[i] == b[o])	dp[i][o] = dp[i-1][o-1]+1;
			else	dp[i][o] = max(dp[i-1][o], dp[i][o-1]);
		}
	}
	cout << len - dp[len][len] << endl;
	return 0;
	
} 
