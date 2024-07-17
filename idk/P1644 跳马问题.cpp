//P1644 ÌøÂíÎÊÌâ
#include <iostream>
using namespace std;

int a[20][20];
//int step[8][2] = { {1, 2}, {1, -2}, {2, -1}, {2, 1}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1} };

int main(){
	int n, m;
	cin >> m >> n;
	a[0][0] = 1;
   	for(int i = 0; i <= n; i++){
   		for(int o = 0; o <= m; o++){
   			//if(i-2 > 0 && o-1) 
			if(i-2 >= 0 && i-2 <n && o-1 <= m) a[i][o] += a[i-2][o-1];
			if(i-2 >= 0 && i-2 <n && o+1 <= m) a[i][o] += a[i-2][o+1];
			if(i-1 >= 0 && i-1 <n && o+2 <= m) a[i][o] += a[i-1][o+2];
			if(i-1 >= 0 && i-1 <n && o-2 <= m) a[i][o] += a[i-1][o-2];
   			//a[i][o] = a[i-2][o-1]+a[i-2][o+1]+a[i-1][o+2]+a[i-1][o+2];
		   }
   		
	   }

    cout << a[n][m];
    return 0;
}
