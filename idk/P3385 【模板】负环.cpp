//改成spfa 
//P1339 [USACO09OCT] Heat Wave G
//似乎是一个dijkstra算法 总之抄ppt就对了！
// btw chatgpt真好使
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int T;
int const MAXM = 3210, MAXN = 2010;
void SPFA(int u, int n);

int p[MAXN], len, cnt[MAXN];
long long dis[MAXN], minn;
bool vis[MAXN];
struct edge {
	int v, w, next;
} e[MAXM << 1];

void init(){
	memset(p, -1, sizeof(p));
	len = 0;
}

void insert(int u, int v, int w){
	e[len].v = v; e[len].w = w, e[len].next = p[u];
	p[u] = len++;
}

int main(){
	init();
	cin >> T;
	for(int i = 0; i < T; i++){
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			insert(u, v, w);
			if(w >= 0)	insert(v, u, w);
		} 
		SPFA(1, n);
		//cout << dis[t];
	}

	
	return 0;
}

void SPFA(int u, int n){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[u] = 0;
	vis[u] = 1;
	cnt[u]++;
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		u = q.front();
		q.pop();
		vis[u] = 0;
		for	(int i = p[u]; i != -1; i = e[i].next) {
			int v = e[i].v, w = e[i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					q.push(v);
					vis[v] = true;
					cnt[v]++;
				}
			}
			if(cnt[v] >= n+1){
				cout << "YES" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}
