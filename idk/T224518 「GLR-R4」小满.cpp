//T224518 ¡¸GLR-R4¡¹Ð¡Âú
#include <iostream>
using namespace std;

long long T;
long long n;
long long ans[6];

long long op1(long long p);
long long op2(long long p, long long d);
void bin(long long m);

int main(void){
	
	cin >> T;
	int op;
	int num;
	for(int o = 0; o < T; o++){
		ans[o] = 0;
		cin >> n;
		for(int u = 0; u < n; u++){
			cin >> op;
			if(op == 1){
				ans[o] = op1(ans[o]);
			}
			else{
				int d;
				cin >> d;
				ans[o] = op2(ans[o], d);
			}
		}
	}
	
	for(int w = 0; w < T; w++){
		bin(ans[w]);
		//cout <<"ans:  "<< ans[w] << endl;
	}
	return 0;
	
} 

long long op1(long long p)
{
	return p*2;
}

long long op2(long long p, long long d){
	return p+d;
}

void bin(long long m){
	int length = 0;
	int bin[1000];
	while(m / 2){
		bin[length] = m % 2;
		m = m / 2;
		length++;
	}

	bin[length] = m;
	length++;
	
	for(int o = length - 1; o >= 0; o--){
		cout << bin[o];
	}
	cout << endl;

} 
