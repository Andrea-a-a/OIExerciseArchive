//T349349 [yLOI2022] 西施江南
//首先先输进来 然后求一下各种东西 可能能做到一边输入一边算？
//sum应该会爆 还没想好 
#include <iostream> 
using namespace std;

int T, n;


int gcd(unsigned long long a, int b){
	if(b == 0)	return a;
	return gcd(b, a%b);
}

unsigned long long lcm(unsigned long long a, int b){
	return(a*b)/gcd(a,b);
}

int main() {
	cin >> T;
	for(int i = 0; i < T; i++) {
		int n;
		unsigned long long m = 1, d = 1, sum = 1;
		cin >> n;
		for(int o = 0; o < n; o++) {
			int a;
			cin >> a;
			sum *= a;
			d = gcd(d, a);
			m = lcm(m, a);

		}
		if(m*d == sum)	cout << "Yes"<< endl;
		else 			cout << "No" << endl;
	} 
}

