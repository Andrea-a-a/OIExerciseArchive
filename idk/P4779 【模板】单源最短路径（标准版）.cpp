//P3371 【模板】单源最短路径（弱化版） <-目前是这个 懒得改了 就是改一下maxm和maxn和输出的问题喵！
//滚去学spfa.jpeg 
//P4779 【模板】单源最短路径（标准版）
//很显然是用下面的改的 堆优化的dijkstra 试图抄抄ppt 不会了再说（ 
//P1339 [USACO09OCT] Heat Wave G
//似乎是一个dijkstra算法 总之抄ppt就对了！
// btw chatgpt真好使
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set> 
#include <cstdio>
#include <cmath> 
using namespace std;

int n, m, a;
int const MAXM = 500010;
int const MAXN = 10010;

void Dijkstra(int u);
typedef pair<long long, int> PII; 

int p[MAXN], len;
int dis[MAXN], minn;
bool vis[MAXN];
set<PII> s;

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
	cin >> n >> m >> a;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		insert(u, v, w);
		//insert(v, u, w);
	} 
	Dijkstra(a);
	for(int i = 1; i <= n; i++){
		if(dis[i] == 0x7f7f7f7f)	cout << "2147483647" << " ";
		else cout << dis[i] << " ";
	}
	return 0;
}

void Dijkstra(int u){
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[u] = 0;
	s.insert(make_pair(0, u));
	while (s.size()) {
		set<PII>::iterator it = s.begin();
		u = it->second;
		s.erase(*it);
		vis[u] = 1;
		for (int i = p[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			long long w = e[i].w;
			if (!vis[v] && dis[u] + w < dis[v]) {
				s.erase(make_pair(dis[v],v));
				dis[v] = dis[u] + w;
				s.insert(make_pair(dis[v], v));
			} 
		}
	}
}
