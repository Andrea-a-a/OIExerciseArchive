//P3366 【模板】最小生成树
//我永远讨厌链式前向星！
//这是一个prim（朴素）算法的最小生成树 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010, MAXM = 2e5+10;
int n, m, cnt, p[MAXN], len = 1;
int dist[MAXN], used[MAXN];
struct edge {
	
	int u, v, w, next;
} e[MAXM << 1];

bool cmp(edge a, edge b);
int get(int x);
int Prim();


void insert(int u, int v, int w) {
	e[len].u = u, e[len].v = v, e[len].w = w, e[len].next = p[u];
	p[u] = len++;
	
}
void init() {
	memset(p, -1, sizeof(p));
	len = 0;
}
int main(){
	init();
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		insert(x, y, w);
	}
	int ans = Prim();
	if(cnt != n-1){
		cout << "orz";
		return 0;	
	} 
	cout<< ans;
	return 0;
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int Prim() {
	memset(dist, 0x3f, sizeof(dist));
	memset(used, false, sizeof(used));
	int sum = 0;
	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		int min_v = -1, min_d = 0x3f3f3f3f;
		for(int j = 1; j <= n; j++) {
			if(!used[j] && dist[j] < min_d) {
				min_d = dist[j];
				min_v = j;
			} 
		}
		sum += min_d;
		cnt++;
		used[min_v] = true;
		for (int o = p[min_v]; i != -1; i = e[o].next) {
			int v = e[o].v;
			dist[v] = min(dist[v], e[i].w);
		}
	}
	return sum;
}
