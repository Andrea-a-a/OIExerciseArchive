//P1182 数列分段 Section II 
//P1824 进击的奶牛
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
//#define INF 1e9
int N, C, a[MAXN];

int p(int x){
	int cnt = 1;
	int tot = 0;
	for(int i = 1; i <= N; i++){
		if(a[i]+tot <= x){
			tot += a[i];
		}
		else{
			cnt++;
			tot = a[i];
		}
	}
	
	return cnt;
}

int main(){
	cin >> N >> C;
	//cout << "?" << endl ;
    int l=0, r;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
		//cout << "*" << i<<"* "<<a[i]<< endl ;
	}
	//cout <<l<< "?" <<r<< endl ;
	//sort(a+1, a+1+N);
	//cout << "?";
	int ans, mid;
	//想好你要传什么
	//cout << p(4) <<"!"<< endl; 
	while(l <= r) {
		int o = p(mid = (l+r)>>1);
		if(o <= C)	ans = mid, r = mid-1;
		else	 l = mid+1;
	}
	//cout << "** p(28729) **" << p(28729) << endl;
	//if(p(ans+1)) 	cout<<ans+1;
 cout << ans;
	return 0;
}
 
