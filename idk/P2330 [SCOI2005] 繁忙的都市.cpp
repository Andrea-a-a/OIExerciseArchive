//P2330 [SCOI2005] 繁忙的都市
//P3366 【模板】最小生成树
//我永远讨厌链式前向星！
//柠檬茶真好喝 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 310, MAXM = 1e5+10;
int len = 1;
int n, m, ans = -1e5;
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

	cin >> n >> m;

	for(int i = 1; i <= m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		insert(x, y, w);
	}
	int ans = Kruskal();
	
	cout<< n-1 << " " << ans;
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
		if (u != v) {
			fa[v] = u;
			ans = max(ans, e[i].w);
		}
	}

	return ans;
}
