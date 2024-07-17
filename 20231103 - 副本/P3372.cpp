//P3372 非常朴素的线段树！
//试图尝试0-index
//不能用0-index 因为0<<1还是0
//maxn<<1居然会爆欸 为啥捏
//因为好像mid<<1+1不一定是连着排的？
#include <iostream>
using namespace std;
int const MAXN = 1e5+10;
long long a[MAXN];
long long b[MAXN << 2];
long long t[MAXN << 2] = {0};
long long le[MAXN << 2];
//long long ans;

//向上更新pushup
void pushup(int id){
    b[id] = b[id << 1]+b[id << 1 | 1];
}

//向下更新pushdown
void pushdown(int id){
    if(t[id]){
        b[id<<1] += t[id] * le[id<<1];
        b[id<<1|1] += t[id] * le[id<<1|1];
        t[id << 1] += t[id];
        t[id << 1 | 1] += t[id];
        t[id] = 0;
    }
}

//建树build
void build(int l, int r, int id){


    le[id] = r-l+1;
    if(l == r){
        b[id] = a[l];
        return;
    }
    
    int mid = (l+r) >> 1;
    build(l, mid, id << 1);
    build(mid+1, r, id << 1 |1);
    pushup(id);

}


//区间加更新update
void update(int x, int y, int l, int r, int v, int id){
    if(x <= l && y >= r){
        b[id] += v * le[id];
        t[id] += v;
        return;
    }
    pushdown(id);
    int mid = (l+r) >> 1;
    if(x <= mid)    update(x, y, l, mid, v, id<<1);
    if(y > mid)     update(x, y, mid+1, r, v, id<<1|1);
    pushup(id);
}

//查询query
long long query(int x, int y, int l, int r, int id){
    if(x <= l && y >= r){
        return b[id];
    }
    pushdown(id);
    int mid = (l+r) >> 1;
    long long ans = 0;
    if(x <= mid)    ans+=query(x, y, l, mid, id<<1);
    if(y > mid)     ans+=query(x, y, mid+1, r,  id<<1|1);
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, n, 1);
    //cout << "m=" << m << "n=" << n;
    for(int o = 0; o < m; o++){
        int opt;
        cin >> opt;
        if(opt == 1){
            int x, y, v;
            cin >> x >> y >> v;
            //cout << "INPUTED!" << endl;
            update(x, y, 1, n, v, 1);
            //cout << "UPDATED!" << endl << endl;
        }
        else{
            int x, y;

            cin >> x >> y;
            //cout << endl<<"query:"<< query(x, y, 1, n, 1) << endl;
            cout << query(x, y, 1, n, 1) << endl;
        }
    }
    return 0;
}