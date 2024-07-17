//P1196 [NOI2002] 银河英雄传说 
//P3367 【模板】并查集 
#include <iostream>
#include <cmath>

using namespace std;
int get(int x);
void merge(int u, int v);

int fa[30010], dis[30010], size[30010];
int T=0;

int main(){
	cin >> T;
	for (int i = 1; i <= 30009; i++) {
		fa[i] = i;
		size[i] = 1;
	}
	int x, y;
	char opt; 
	for(int i = 0; i < T; i++){
		cin >> opt >> x >> y;
		if (opt == 'C') {
			if (get(x) == get(y)){
				cout << abs(dis[y]-dis[x])-1 << endl; 
			} 
			else {
				cout << "-1" << endl;
			}
		} else {
			merge(x, y);
		}
	} 
	return 0;
} 

int get(int x) {
	if (x == fa[x]) return x;
	int tmp=fa[x];
	fa[x]=get(fa[x]);
	dis[x]+=dis[tmp];
	return fa[x];
}

void merge(int u, int v){
	int fu = get(u), fv = get(v);
	if(fu != fv) {
		dis[fu] = size[fv];
		fa[fu] = fv;
		size[fv] += size[fu];
		//把u接在v下面 
	}
}
