//P2678 [NOIP2015 提高组] 跳石头
//P1182 数列分段 Section II 
//P1824 进击的奶牛
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
//#define INF 1e9
int L, N, C, a[MAXN];

bool p(int x){
	int cnt = 0;
	int last = 0;
	for(int i = 1; i <= N+1; i++){
		if(a[i]-a[last] >= x){
			last = i;
		}
		else{
			cnt++;
		}
	}
	//if(a[N+1]-a[last] >= x && cnt<=C)	return true;
	if(cnt<=C)	return true;
	else	return false;
}

int main(){
	cin >> L >> N >> C;
	//cout << "?" << endl ;
    int l=0, r=L+10;
    a[0] = 0;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
        //l = max(l, a[i]);
        //r += a[i];
		//cout << "*" << i<<"* "<<a[i]<< endl ;
	}
	a[N+1] = L;
	//cout <<l<< "?" <<r<< endl ;
	//sort(a+1, a+1+N);
	//cout << "?";
	int ans, mid;
	//想好你要传什么
	//cout << p(4) <<"!"<< endl; 
	while(l <= r) {
		//int o = p(mid = (l+r)>>1);
		if(p(mid = (l+r)>>1))	ans = mid,l = mid+1;
		else	  r = mid-1;
	}
	//cout << "** p(28729) **" << p(28729) << endl;
	//if(p(ans+1)) 	cout<<ans+1;
	cout << ans;
	return 0;
}
 
