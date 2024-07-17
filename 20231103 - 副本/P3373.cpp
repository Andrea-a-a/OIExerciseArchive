//P3373 3372改 先乘后加
//P3372 非常朴素的线段树！
#include <iostream>
//#include <cstring>
using namespace std;
//int const MAXN = 10;
int const MAXN = 1e5+10;
long long a[MAXN];
long long b[MAXN << 2];
long long t[MAXN << 2] = {0};
long long p[MAXN << 2];
const int s = 571373;
//long long le[MAXN << 2];
//long long ans;

//向上更新pushup
void pushup(int id){
    b[id] = b[id << 1]%s+b[id << 1 | 1]%s;
    b[id] %= s;
}

//向下更新pushdown
void pushdown(int id, int l, int r){
    
        b[id<<1] *= p[id]%s;
        b[id<<1] %= s;
        b[id << 1 | 1] *= p[id]%s;
        b[id<<1|1] %= s;
        int mid = (l+r)>>1;
        b[id<<1] += (t[id]%s) * ((mid-l+1)%s);
        b[id<<1] %= s;
        b[id<<1|1] += (t[id]%s) * ((r-mid)%s);
        b[id<<1|1] %= s;

        
        p[id<<1] *= p[id]%s;
        p[id<<1] %= s;
        p[id << 1 | 1] *= p[id]%s;
        p[id<<1|1] %= s;

                t[id << 1] *= p[id]%s;
        t[id << 1|1] %= s;
        t[id << 1 | 1] *= p[id]%s;
        t[id << 1|1] %= s;

        t[id << 1] += t[id]%s;
        t[id << 1] %= s;
        t[id << 1 | 1] += t[id]%s;
        t[id << 1] %= s;

        p[id] = 1;
        t[id] = 0;
        
    // }
    // else if(t[id]){
    //     int mid = (l+r)>>1;
    //     b[id<<1] += (t[id]%s) * ((mid-l+1)%s);
    //     b[id<<1] %= s;
    //     b[id<<1|1] += (t[id]%s) * ((r-mid)%s);
    //     b[id<<1|1] %= s;
    //     t[id << 1] += t[id]%s;
    //     t[id << 1] %= s;
    //     t[id << 1 | 1] += t[id]%s;
    //     t[id << 1] %= s;
    //     t[id] = 0;
    // }
}

//建树build
void build(int l, int r, int id){


    //le[id] = r-l+1;
    if(l == r){
        b[id] = a[l];
        return;
    }
    
    int mid = (l+r) >> 1;
    build(l, mid, id << 1);
    build(mid+1, r, id << 1 |1);
    pushup(id);

}


//区间加更新updateA
void updateA(int x, int y, int l, int r, int v, int id){
    if(x <= l && y >= r){
        b[id] += (v%s) * ((r-l+1)%s);
        b[id] %= s;
        t[id] += v%s;
        t[id] %= s;
        return;
    }
    if(t[id] || p[id]!=1) pushdown(id, l, r);
    int mid = (l+r) >> 1;
    if(x <= mid)    updateA(x, y, l, mid, v, id<<1);
    if(y > mid)     updateA(x, y, mid+1, r, v, id<<1|1);
    pushup(id);
}

//区间乘更新updateM
void updateM(int x, int y, int l, int r, int v, int id){
    if(x <= l && y >= r){
        b[id] *= v%s;
        b[id] %= s;
        p[id] *= v%s;
        p[id] %= s;
        t[id] *= v%s;
        t[id] %= s;
        return;
    }
    if(t[id] || p[id]!=1) pushdown(id, l, r);
    int mid = (l+r) >> 1;
    if(x <= mid)    updateM(x, y, l, mid, v, id<<1);
    if(y > mid)     updateM(x, y, mid+1, r, v, id<<1|1);
    pushup(id);
}

//查询query
long long query(int x, int y, int l, int r, int id){
    if(x <= l && y >= r){
        return b[id]%s;
    }
    pushdown(id, l, r);
    int mid = (l+r) >> 1;
    long long ans = 0;
    if(x <= mid)    ans+=query(x, y, l, mid, id<<1)%s; ans%= s;
    if(y > mid)     ans+=query(x, y, mid+1, r,  id<<1|1)%s; ans%= s;
    return ans;
}

int main(){
    for(int i = 0; i <= 400039; i++)    p[i] = 1;
    //for(int i = 0; i <= 39; i++)    p[i] = 1;
    
    int q;
    int n, m;
    cin >> n >> m >> q;
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
            updateM(x, y, 1, n, v, 1);
            //cout << "UPDATED!" << endl << endl
            //cout << endl << "p " << p[1] << "t:" << t[5] << endl; 
        
        }
        else if(opt == 2){
            int x, y, v;
            cin >> x >> y >> v;
            //cout << "INPUTED!" << endl;
            updateA(x, y, 1, n, v, 1);
            //cout << "UPDATED!" << endl << endl;
        }
        else{
            int x, y;

            cin >> x >> y;
            //cout << endl<<"query:"<< query(x, y, 1, n, 1) << endl;
            cout << query(x, y, 1, n, 1)%q << endl;
        }
    }
    return 0;
}