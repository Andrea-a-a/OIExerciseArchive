//P3372 非常朴素的线段树！
//试图尝试0-index
//不能用0-index 因为0<<1还是0
#include <iostream>
#include <cmath>
using namespace std;
//#define long long double;
int const MAXN = 2e5+10;
int a[MAXN];
double sinn[MAXN << 2];
double coss[MAXN << 2];
long long t[MAXN << 2];
//long long le[MAXN << 2];
//long long ans;

//sinn[]维护区间sin和
//coss[]维护取件cos和

//向上更新pushup
void pushup(int id){
//    sinn[id] = sinn[id << 1]*coss[id<<1|1]+coss[id << 1]*sinn[id<<1|1];
//    coss[id] = coss[id<<1] * coss[id<<1|1] - sinn[id<<1] * sinn[id<<1|1];
	sinn[id] = sinn[id<<1] + sinn[id<<1|1];
	coss[id] = coss[id<<1] + coss[id<<1|1];
}

//向下更新pushdown
void pushdown(int id, int l, int r){
    if(t[id]){
    	int mid = (l+r)>>1;
    	double o,e;
		o = sinn[id << 1]*cos(t[id])+coss[id << 1]*sin(t[id]);
		e = coss[id<<1] * cos(t[id]) - sinn[id<<1] * sin(t[id]);
		sinn[id<<1] = o;
		coss[id<<1] = e;
		o = sinn[id << 1|1]*cos(t[id])+coss[id << 1|1]*sin(t[id]);
		e = coss[id<<1|1] * cos(t[id]) - sinn[id<<1|1] * sin(t[id]);
		sinn[id<<1|1] = o;
		coss[id<<1|1] = e;
        t[id << 1] += t[id];
        t[id << 1 | 1] += t[id];
        t[id] = 0;
    }
}

//建树build
void build(int l, int r, int id){
    //le[id] = r-l+1;
    if(l == r){
        sinn[id] = sin(a[l]);
        coss[id] = cos(a[l]);
        //cout<<"build"<<sinn[id] <<" " << coss[id] <<" "<<l<<" "<<id<<endl;
        return;
    }

    int mid = (l+r) >> 1;
    build(l, mid, id << 1);
    build(mid+1, r, id << 1 |1);
    pushup(id);

}


//区间加更新update
void update(int x, int y, int l, int r, int v, int id){
            //cout<<endl<<"l= "<<l<<" r= "<<r<<" sinsum "<<sinn[id]<<" cossum " <<coss[id]<<endl;

    if(x <= l && y >= r){
        double o, e;
		o = sinn[id]*cos(v)+coss[id ]*sin(v);
		e = coss[id] * cos(v) - sinn[id] * sin(v);
        sinn[id] = o;
        coss[id] = e;
                    //cout<<endl<<"l= "<<l<<" r= "<<r<<" sinsum "<<sinn[id]<<" cossum " <<coss[id]<<endl;

        //sinn[id] = sinn[id << 1]*coss[id<<1|1]+coss[id << 1]*sinn[id<<1|1];
        //coss[id] = coss[id<<1] * coss[id<<1|1] - sinn[id<<1] * sinn[id<<1|1];
        t[id] += v;
        return;
    }
    pushdown(id, l, r);
    int mid = (l+r) >> 1;
    if(x <= mid)    update(x, y, l, mid, v, id<<1);
    if(y > mid)     update(x, y, mid+1, r, v, id<<1|1);
    pushup(id);
}

//查询query
double query(int x, int y, int l, int r, int id){
               // cout<<endl<<"l= "<<l<<" r= "<<r<<" sinsum "<<sinn[id]<<" cossum " <<coss[id]<<endl;

    if(x <= l && y >= r){
        return sinn[id];
        }
    pushdown(id, l, r);
    int mid = (l+r) >> 1;
    double ans = 0;
    if(x <= mid)    ans+=query(x, y, l, mid, id<<1);
    if(y > mid)     ans+=query(x, y, mid+1, r,  id<<1|1);
    return ans;
}

int main(){
    cout.precision(1);
    //freopen("test1.txt","r", stdin);
    int n, m;
    cin >> n ;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, n, 1);

               // printf("\n%0.1f \n\n",query(5, 5, 1, n, 1));

    cin >> m;
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
            //cout << query(x, y, 1, n, 1) << endl;
            printf("%0.1f\n",query(x, y, 1, n, 1));
        }
    }
                    //printf("\n%0.1f\n\n",query(5, 5, 1, n, 1));

    return 0;
}
