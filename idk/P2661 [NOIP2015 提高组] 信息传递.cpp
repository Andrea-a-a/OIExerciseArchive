//P2661 [NOIP2015 提高组] 信息传递
//P3367 【模板】并查集 
#include <iostream>

using namespace std;
int get(int x);
void merge(int u, int v);

const int MAXN = 2e5+10;
int fa[MAXN], dis[MAXN];
int n, ans = 0x7f7f7f7f;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++){
		int t; 
		cin >> t;
		merge(i, t);

	} 
	cout << ans; 
	return 0;
} 

int get(int x) {
	if (x == fa[x]) return x;
	int tmp=fa[x];//深坑，解释见上
	fa[x]=get(fa[x]);//浅坑2
	dis[x]+=dis[tmp];
	return fa[x];
}

void merge(int u, int v){
	int fu = get(u), fv = get(v);
	if(fu != fv) {
		dis[u] = dis[v]+1;
		fa[fu] = fv;
		//把u接在v下面 

	}
	else	 ans = min(ans, dis[v]+1);
}
