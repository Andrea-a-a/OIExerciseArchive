//P3870 [TJOI2009] 开关
//普通的线段树？len-sum
//灯在初始的时候都是关着的
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e5+10;
//int a[MAXN];
int p[MAXN << 2];
bool t[MAXN << 2];

//pushup向上更新区间和
void pushup(int id, int l, int r){
    p[id] = p[id<<1]+p[id<<1|1];
}

//pushdown向下更新懒标记
void pushdown(int id, int l, int r){
    int mid = (l+r)>>1;
    if(!t[id])//if t[id] == 0
    {
        p[id<<1] = mid-l+1-p[id<<1];
        //else    p[id<<1] = 0;
        p[id<<1|1] = r-mid-p[id<<1|1];
        //else    p[id<<1|1] = 0;
        t[id<<1] = !t[id<<1];
        t[id<<1|1] = !t[id<<1|1];
        t[id] = 1;
    }
}
//build建树
//void build(int id, int l, int r)

//query查询
int query(int x, int y, int l, int r, int id){
    if(x<=l&&r<=y)  return p[id];
    pushdown(id, l, r);
    int mid = (l+r)>>1;
    int ans = 0;
    if(x<=mid)  ans+=query(x, y, l, mid, id<<1);
    if(y>mid)  ans +=query(x, y, mid+1, r, id<<1|1);
    return ans;

}

//update更新
void update(int x, int y, int l, int r, int id){
    if(x<=l&&r<=y){
         p[id] = r-l+1-p[id];
        t[id] = !t[id];
            //if(t[id] == 0)  [id] = r-l+1;
           // else    p[id] = 0;
            return;
    }
    pushdown(id, l, r);
    int mid = (l+r)>>1;
    //int ans = 0;
    if(x<=mid)  update(x, y, l, mid, id<<1);
    if(y>mid)   update(x, y, mid+1, r, id<<1|1);
    pushup(id, l, r);


}

//main主函数
int main(){
    //memset(t, sizeof(t), 1);
    //cout <<endl<<t[1]<<t[2]<<t[3]<<endl;
    for(int i = 1; i <MAXN*2; i++)    t[i] = 1;

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int opt, x, y;
        cin >> opt >> x >> y;
        if(opt == 0){
            update(x, y, 1, n, 1);
        }
        else{
            cout << query(x, y, 1, n, 1)<<endl;
        }
    }
    return 0;
}
