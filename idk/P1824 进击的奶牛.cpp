//P1824 ½ø»÷µÄÄÌÅ£
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e7 + 10;
int N, C, a[MAXN];

bool p(int x){
	int cnt = 0, last = -10000;
	for(int i = 1; i <= N; i++){
		if(a[i]-last >= x){
			cnt++;
			last = a[i];
		}
	}	
	return cnt >= C;
}
int main(){
	cin >> N >> C;
	for(int i = 1; i <=N; i++){
		cin >> a[i];
		//cout << "*" << i<<"* "<<a[i]<< endl ;
	}
	//cout << "?" << endl ;
	sort(a+1, a+1+N);
	//cout << "?";
	int l = 0, r = 1e9, ans, mid;
	//cout << p(4) <<"!"<< endl; 
	while(l <= r) {
		mid = (l+r)/2;
		if(p(mid))	ans = mid, l = mid+1;
		else	r = mid-1;
	}
	//cout << "** p(28729) **" << p(28729) << endl;
	//if(p(ans+1)) 	cout<<ans+1;
	cout << ans;
	return 0;
}
 
