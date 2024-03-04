#include <bits/stdc++.h>
using namespace std;
int n, a[6];
int main(){
	//int start = clock();
	//freopen("test1.in", "r", stdin);
	//freopen("test1.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= 5; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	do{
		for(int i = 1; i <= 5; i++){
			cout << a[i] << ' ';
		}
		cout << endl;
	}while(next_permutation(a+1,a+n+1));
    //int en = clock();
    //cout << en-start;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
