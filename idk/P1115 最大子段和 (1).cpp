//P1115 最大子段和
//贪心？反正是抄题解 奇妙的思路增加了！ 
#include <iostream>
using namespace std; 

int n, a[200020], b[200020];
int ans = -2147483647;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i == 0)	b[i] = a[i];
		else b[i] = max(a[i], b[i-1]+a[i]);
		ans = max(ans, b[i]);
	}
	cout << ans;
	return 0;
}
