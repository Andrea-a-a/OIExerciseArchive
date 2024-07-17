//P1339 [USACO09OCT] Heat Wave G
//似乎是一个dijkstra算法 总之抄ppt就对了！
// btw chatgpt真好使
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, s, t;
int const maxm = 6210;
void Dijkstra(int u);

int p[2510], len;
int dis[2510], minn;
bool vis[2510];
struct edge {
	int v, w, next;
} e[maxm << 1];

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
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		insert(u, v, w);
		insert(v, u, w);
	} 
	Dijkstra(s);
	cout << dis[t];
	return 0;
}

void Dijkstra(int u){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[u] = 0;
	vis[u] = 1;
	for(int i = 1; i <= n; i++){
		int minn = 0x3f3f3f3f;
		for(int j = p[u]; j != -1; j = e[j].next){
			int v = e[j].v, w = e[j].w;
			if (!vis[v]) dis[v] = min(dis[v], dis[u] + w);
		}
		for (int j = 1; j <= n; j++){
			if(!vis[j] && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		}
		
		vis[u] = 1;

		if (minn == 0x3f3f3f3f) return;
	}
}
