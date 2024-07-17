//P1102 A-B 数对
//感谢深入浅出！
//思路：先输进来，然后sort， 枚举A，找b+c的个数（使用lower_bound和upper_bound)
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e5+10;
int n, c, a[MAXN];
long long ans;
//"这里注意ans要存long long，其他的存不存无所谓。否则第三个点会错。" 


int main() {
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i = 0; i < n; i++){
		ans += upper_bound(a, a+n, a[i]+c) - lower_bound(a, a+n, a[i]+c);
	}
	cout << ans;
	return 0;
} 
