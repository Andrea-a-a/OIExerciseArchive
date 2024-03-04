#include <iostream>
using namespace std;
int m,n;
int dp[100][100][100];
int a[100][100];

int main(){
	cin >> m>>n;
	//int o=1,i=1,p=1;
	for(int i = 1; i <= m; i++){
		for(int o = 1; o <= n; o++){
			//int tmp;
			cin >> a[i][o];
		}
	}
		//cout<<"meow?"<<o<<i<<p<<a[o][i]<<endl;
	//cout<<a[7][12]<<endl;
	for(int w = 1; w<= m; w++ ){
		for(int e = 1; e <= n; e++){
			for(int k = 1; k<= m; k++){
				int l = w+e-k;
				if(l<=0)	break;
				if(w>=l)	continue;
				//if(w!=k){
						dp[w][e][k] = max(max(dp[w-1][e][k-1],dp[w-1][e][k]),max(dp[w][e-1][k-1],dp[w][e-1][k]))+a[w][e]+a[k][l];

				//}
				//else dp[w][e][k] = max(max(dp[w-1][e][k-1],dp[w-1][e][k]),max(dp[w][e-1][k-1],dp[w][e-1][k]))+a[w][e];

			}
		}
	}
	cout << dp[m][n-1][m-1];
	return 0;
}
