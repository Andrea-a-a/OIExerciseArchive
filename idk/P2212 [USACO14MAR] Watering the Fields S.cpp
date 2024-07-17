//P2212 [USACO14MAR] Watering the Fields S
//P1194 买礼物
//P1546 [USACO3.1] 最短网络 Agri-Net 
//P3366 【模板】最小生成树
//我永远讨厌链式前向星！
//柠檬茶真好喝 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2010, MAXM = 5e6;
int len = 1;
int n, c, m, cnt;
int x[MAXN], y[MAXN];
int fa[MAXN];
struct edge {
	int u, v, w;
} e[MAXM << 1];

bool cmp(edge a, edge b);
int get(int x);
int Kruskal();


void insert(int u, int v, int w) {
	e[len].u = u, e[len].v = v, e[len].w = w;
	len++;
}

int main(){
	cin >> n>>c;
	m = n*n/2;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int o = i+1; o <= n; o++) {
			int w = (x[i]-x[o])*(x[i]-x[o]) + (y[i]-y[o])*(y[i]-y[o]); 
			insert(i, o, w);	
		}
	}
	int ans = Kruskal();
	if(cnt != n-1){
		cout << "-1";
		return 0;
	}
	cout<< ans;
	return 0;

}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int Kruskal() {
	int sum = 0;
	for (int i = 1; i <= n; i++)	fa[i] = i;
	sort(e+1, e+m+1, cmp);
	for (int i = 1; i <= m; i++) {
		int u = get(e[i].u);
		int v = get(e[i].v);
		/* “优惠”后的价格可能反而比商品原价高。*/
		if (u != v&&e[i].w >= c) {
			fa[v] = u;
			sum += e[i].w;
			cnt++;
		}
	}

	return sum;
}
