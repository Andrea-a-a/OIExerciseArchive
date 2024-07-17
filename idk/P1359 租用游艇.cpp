//P1359 租用游艇
//总之就是抄ppt！以及show boat好看的 和这个题意外搭配（
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int g[210][210], dp[210][210];
void floyd(int n);

int main(){
	int n;
	memset(g, 0x3f, sizeof(g));
	cin >> n;
	for(int i = 0; i < n-2; i++){
		g[i][i] = 0;
		for(int o = i+1; o <= n-1; o++){
			cin >> g[i][o];
			//g[o][i] = g[i][o]; 
		}
	}
	g[n-1][n-1] = 0;
	floyd(n);
	cout << g[0][n-1];
	return 0;
} 

void floyd(int n){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
			}
		}
	}
}

/*为何成66分呢？因为这个程序最大的漏洞是把它当成无向图处理了，应当当成有向图去做。

所以要把 a[v][u]=x;删掉。

删掉它就是令人满意的AC代码了！
-----金庆涵
*/

/*你学到了什么：
用min 
