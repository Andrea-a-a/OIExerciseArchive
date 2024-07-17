//P1892 [BOI2003] 团伙
//P3367 【模板】并查集 
#include <iostream>

using namespace std;
int get(int x);
void merge(int u, int v);

int fa[10010];
int M, N, ans;

int main(){
	cin >> N >> M;
	ans = 0;
	for (int i = 1; i <= 5010; i++) fa[i] = i;
	
	char opt;
	int x, y;
	for(int i = 0; i < M; i++){
		cin >> opt >> x >> y;
		if (opt == 'E') {
			merge(N+x, y);
			merge(N+y, x);
		} else {
			merge(x, y);
		}
	} 
	for(int i = 1; i <= N; i++){
		if(get(i) == i)	ans++;
	}
	cout << ans;
	return 0;
} 

int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

void merge(int u, int v){
	int fu = get(u), fv = get(v);
	if (fu != fv) fa[fu] = fv;
}
