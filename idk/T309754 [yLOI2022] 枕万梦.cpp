//T309754 [yLOI2022] 枕万梦
//思路：首先把两个序列搞出来，然后比较字典序
//讨厌oi赛制……
//草 肯定会爆空间吧
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m;
//int a[10010][10010];

struct node{
	int id;
	int a;
	friend bool operator <(node n1, node n2) {
		int i;
		bool temp;
		for(i = 1; i <= m+1; i++){
			if(n1.a*pow(n1.id, i-1) > n2.a*pow(n2.id, i-1)){
				temp = 1;
				break;
			}
			else if(n1.a*pow(n1.id, i-1) < n2.a*pow(n2.id, i-1)){
				temp = 0;
				break;
			}
			
		}
		return temp;
	}
} p[10010];

priority_queue<node> q;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	p[i].id = i;
        cin >> p[i].a;
        q.push(p[i]);
    }
    while(!q.empty()){
    	cout << q.top().id << " ";
		q.pop(); 
	}
    //cout << q.top().id;
//    cout << endl;
//    for(int i = 1; i <= n; i++){
//    	for(int o = 0; o < m+1; o++)	cout << a[i][o]; 
//    	cout << endl;
//	}

    return 0;
}
