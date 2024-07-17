//P1644 跳马问题
//思路：dfs，判定是否出界
#include <iostream>

using namespace std;

void dfs(int a, int b);

int n, m, total;

int main(){
	
	cin >> n >> m;
	total = 0;
	dfs(0, 0);
	cout << total;
} 

void dfs(int a, int b){
	if(a < 0 || a > n || b > m)	return;
	if(a == n && b == m) total++;
	else{
		dfs(a+1, b+2);
		dfs(a+2, b+1);
		dfs(a-1, b+2);
		dfs(a-2, b+1);
	}
	
}
