//T266174 ¡¸GLR-R4¡¹Á¢ÏÄ
#include <iostream>
#include <cmath>
using namespace std;

long long m;
long long tri[100000];
long long ter(long long m);
int n;
long long ans[100000];

int main(void){
	cin >> n;
	for(int o = 0; o < n; o++){
		cin >> m;
		if(m % 3 == 0){
			int on = ter(m);
			ans[o] = pow(2,on);
		}
		else if(m % 3 ==  1){
			int on = ter(m);
			ans[o] = pow(2,on-1);
		}
		else ans[o] = 0;
	}
	
	for(int o = 0; o < n; o++){
		cout << ans[o] << endl; 
	}
	
	return 0;

}

long long ter(long long m){
	int length = 0;
	int one = 0;
	
	while(m / 3){
		tri[length] = m % 3;
		if(tri[length] == 1){
			one++;
		}
		m = m / 3;
		length++;
	}
	
	tri[length] = m;
	if(tri[length] == 1){
		one++;
	}
	length++;
	
	return one;

} 
