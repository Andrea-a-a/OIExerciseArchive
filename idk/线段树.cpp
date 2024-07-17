#include <iostream>
using namespace std;
//线段树！ 

long long sum[400100];
long long a[100010];
int opt;
int n, m;

void build(int id, int l, int r);
void pushup(int id);
void pushdown(int id, int l, int r);
void update(int id, int l, int r, int x, int y, int v);
int query(int id, int l, int r, int x, int y);

int main(){
	cin >> n >> m;
	int x, y, k, l, r;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++){
		cin >> opt;
		if(opt == 1){
			cin >> x >> y >> k;
			update(1, 1, n, x, k);
		}else {
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		}
	}
	
}


//pushup 从下往上更新
void pushup(int id){
	sum[id] = sum[id << 1] + sum[id << 1 | 1];
} 

//不论如何先建一个树吧！
void build(int id, int l, int r){
	lazy[id] = 0; 
	if (l==r){
		minv[id] = a[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, 1, mid+1, r);
	pushup(id);
}

//pushdown 懒懒 从上往下更新一层
//因为是求和所以要+lazy*区间包含的数的数量 
//所以还需要l和r（（（ 
void pushdown(int id, int l, int r) {
	if (lazy[id]) {
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
		sum[id << 1] = sum[id << 1] + lazy[id] * (mid-l+1);
		sum[id << 1 | 1] = sum[id << 1 | 1] + lazy[id] * (r - mid);
		lazy[id] = 0;
	}
}

//update
void update(int id, int l, int r, int x, int y, int v){
	if (x<=l && r <=y) {
		lazy[id] += v;
		sum[id] = sum[id] + v * (r-l+1);
		return;
	}
	int mid = (l+r) >> 1;
	pushdown(id, l, r, mid);
	if (x <= mid) {
		update(id << 1, l, mid, x, y, v);
	}
	if (y > mid) {
		update(id << 1 |1, mid+1, r, x, y, v);
	}
	pushup(id);
}

//查询
int query(int id, int l, int r, int x, int y) {
	if (x <= l && r <= y) return sum[id];
	int mid = (l + r) >> l, long long ans = 0;
	pushdown(id, l, r, mid);
	if (x <= mid) ans += query(id << 1, l, mid, x, y);
	if (y > mid) ans += query(id << 1|1, mid+1, r, x, y);
	return ans;
} 
