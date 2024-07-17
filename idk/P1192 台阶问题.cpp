//P1192 Ì¨½×ÎÊÌâ
#include <iostream>
#include <string.h>

using namespace std;

int a[100009];
int const m = 100003;
long long ans;

int main(){
	//memset(a, 0, sizeof(a));
	a[0] = 1;
	a[1] = 1;
	
	int n, k;
	cin >> n >> k;
	
	//cout << n << k;
	
	
	for(int o = 2; o <= n; o++){
		for(int i = 1; i <= k; i++){
			if(o-i>=0)
			a[o] += a[o-i]%m;
		}
		//cout << "o:" << o << " a:" << a;
	}
	cout << a[n]%m;
    return 0;
}
