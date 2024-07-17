//P1226 【模板】快速幂 | 取余运算
//好像会了 不确定 再看看
//呃 我推的孩子真好看
#include <iostream>
using namespace std;

long long a, b, p, base, ans;

int main(void){
	cin >> a >> b >> p;
	ans = 1;
	base = a;
	cout << a << "^" << b << " mod " << p << "=";
	//cout << "initialize OK! a = " << a << " b = " << b << " p = " <<p << " ans = " << ans << " base = " << base << endl;
	while(b>0){
		if(b&1){
			ans *= base;
			ans = ans%p;
		}
		base *= base;
		base = base % p;
		b >>= 1;
	}
	cout << ans;
	return 0;
} 
