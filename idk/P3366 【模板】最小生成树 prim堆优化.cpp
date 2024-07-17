//P3366 【模板】最小生成树
//我永远讨厌链式前向星！
//这是一个prim（堆优化）算法的最小生成树 
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 5010, MAXM = 2e5+10;
int n, m, cnt, p[MAXN], len = 0;
int dist[MAXN], used[MAXN];

struct edge {//链式前向星 
	int u, v, w, next;
} e[MAXM << 1];
typedef pair<long long, int> PII; 
set<PII> s; 
//bool cmp(edge a, edge b);
//int get(int x);
int Prim();


void insert(int u, int v, int w) {
	e[len].u = u, e[len].v = v, e[len].w = w, e[len].next = p[u];
	p[u] = len++;
	
}
void init() {//链式前向星 初始化 
	memset(p, -1, sizeof(p));
	len = 0;
}
int main(){
	init();//链式前向星 初始化 
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		insert(x, y, w);
        insert(y, x, w);
	}
	int ans = Prim();
	if(cnt != n){
		cout << "orz";
		return 0;	
	} 
	cout << ans;
	return 0;
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int Prim() {
	memset(dist, 0x3f, sizeof(dist));
	memset(used, false, sizeof(used));
	int sum = 0, u = 1;
	dist[u] = 0;
	s.insert(make_pair(0, u));
	while (s.size()) {
		set<PII>::iterator it = s.begin();
        int d = it->first;
		u = it->second;
		s.erase(*it);
		if(!used[u]) {used[u] = 1;
		sum+=d, cnt++;
        cout << "sum = *" << sum << "*; cnt = *"<<cnt<<"*"<<endl;
		for (int i = p[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			long long w = e[i].w;
			if (!used[v] &&  w < dist[v]) {
				s.erase(make_pair(dist[v],v));
				dist[v] = w;
				s.insert(make_pair(dist[v], v));
			} 
		}
        }
	}
	return sum;
}
