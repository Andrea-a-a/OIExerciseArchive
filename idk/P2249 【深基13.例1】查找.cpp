//P2249 【深基13.例1】查找
//感谢深入浅出捏 争取两天肝完这章（
//简而言之 二分 
#include <iostream> 
using namespace std;

int const MAXN = 1e6+10;
int n, m, a[MAXN];

int find(int q);

int main(void) {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		int q;
		cin >> q;
		cout << find(q) << " ";
	}
	return 0;
}

int find(int q){
	int l = 1;
	int r = n+1;
	while(l < r) {
		int mid = l + (r-l)/2;
		if(a[mid] >= q)	r = mid;
		else	l = mid + 1;
	}
	if(a[l] == q)	return l;
	else return -1;
}
