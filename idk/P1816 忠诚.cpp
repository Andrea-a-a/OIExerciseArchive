#include <iostream>
using namespace std;
//线段树！ 

long long sum[400100];
long long a[100010];
int opt;
int n, m;
int inf = 12345678;

void build(int id, int l, int r);
void pushup(int id);
//void pushdown(int id, int l, int r);
void update(int id, int l, int r, int x, int y, int v);
int query(int id, int l, int r, int x, int y);

int main(){
	cin >> n >> m;
	int l, r;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++){
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
	}
	return 0;
	
}


//pushup 从下往上更新
void pushup(int id){
	sum[id] = min(sum[id << 1], sum[id << 1 | 1]);
} 

//不论如何先建一个树吧！
void build(int id, int l, int r){
	//lazy[id] = 0; 
	if (l==r){
		sum[id] = a[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid+1, r);
	pushup(id);
}

//pushdown 懒懒 从上往下更新一层
//因为是求和所以要+lazy*区间包含的数的数量 
//所以还需要l和r（（（ 
//void pushdown(int id, int l, int r, int mid) {
//	if (lazy[id]) {
//		sum[id << 1] = sum[id << 1] + lazy[id] * (mid-l+1);
//		sum[id << 1 | 1] = sum[id << 1 | 1] + lazy[id] * (r - mid);
//		lazy[id << 1] = lazy[id << 1] + lazy[id];
//		lazy[id << 1 | 1] = lazy[id << 1 | 1] + lazy[id];
//		lazy[id] = 0;
//	}
//}

//update
void update(int id, int l, int r, int x, int v){
	if (l==r) {
		sum[id] = v;
		return;
	}
	int mid = (l+r) >> 1;
	//pushdown(id, l, r, mid);
	if (x <= mid) {
		update(id << 1, l, mid, x, v);
	}
	else{
		update(id << 1 |1, mid+1, r, x, v);
	}
	pushup(id);
}

//查询
int query(int id, int l, int r, int x, int y) {
	if (x <= l && r <= y) return sum[id];
	int mid = (l + r) >> 1, ans = inf;
	//long long ans = 0;
	//pushdown(id, l, r, mid);
	if (x <= mid) ans = min(query(id << 1, l, mid, x, y), ans);
	if (y > mid) ans = min(query(id << 1|1, mid+1, r, x, y), ans);
	return ans;
} 
