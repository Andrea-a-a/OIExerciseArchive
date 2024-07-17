//P3958 [NOIP2017 提高组] 奶酪
//P3367 【模板】并查集 
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e3+10;
//用id=1007代表底面，用id = 1008代表顶面 
int T;
int fa[MAXN];

void merge(int u, int v);
int get(int x);
long long dis(int x1, int y1, int z1, int x2, int y2, int z2); 

int main() {
	cin >> T;
	for(int o = 0; o < T; o++){
		memset(fa, 0, sizeof(fa));
		
		int n, h, r;
		cin >> n >> h >> r;
		for(int i = 1; i < n; i++)	fa[i] = i;
		fa[1007]=1007, fa[1008]=1008;
		
		int x[n+1], y[n+1], z[n+1];
		for(int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i] >> z[i];
			if((z[i]-r) <= 0)	merge(i, 1007);
			if((z[i]+r) >= h)	merge(i, 1008);
			for(int p = 1; p < i; p++){
				if(dis(x[p], y[p], z[p], x[i], y[i], z[i]) <= 4*1ll*r*r)	merge(i, p);
			} 
		}
		if(get(1007) == get(1008))	cout << "Yes" << endl;
		else cout << "No" << endl;
		
	}
	return 0;

}

int get(int x) {
	if(fa[x] == x)	return x;
	return fa[x] = get(fa[x]);
}

void merge(int u, int v) {
	int fu = get(u), fv = get(v);
	if(fu != fv)	fa[fu] = fv;
}

long long dis(int x1, int y1, int z1, int x2, int y2, int z2) {
	return 1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2)+1ll*(z1-z2)*(z1-z2); 
	/* 	最后 20 分的坐标数值很大，乘的时候要用 long long。
		只写成 long long dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2); 是不够的，
		因为这样做是先按 int 类型计算完之后再存入 long long 类型的变量中。
		正确的写法是 long long dis=1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2)+1ll*(z1-z2)*(z1-z2);。
		——whhsteven  */ 
}
