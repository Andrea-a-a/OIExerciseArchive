//P3367 【模板】并查集 
#include <iostream>

using namespace std;
int get(int x);
void merge(int u, int v);

int fa[10010];
int M, N;

int main(){
	cin >> M >> N;
	for (int i = 1; i <= M; i++) fa[i] = i;
	int opt, x, y;
	for(int i = 0; i < N; i++){
		
		cin >> opt >> x >> y;
		if (opt == 2) {
			if (get(x) == get(y)){
				cout << "Y" << endl; 
			} else {
				cout << "N" << endl;
			}
		} else {
			merge(x, y);
		}
	} 
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
