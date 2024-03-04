//U373939
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int t;
int p = 10;
const int MAXN = 1e5;
int a[MAXN];


int main(){
    freopen("test.txt", "r", stdin);
    cin >> t;
    cin.get();
    for(int i = 0; i <= t; i++){
        char s[MAXN];
        memset(a, -1, sizeof(a));
        cin.getline(s, p);
        //cout << a[9]<<" i="<<i<<endl;
        int pos;
        for(int i = 0; i < MAXN; i++){
            if(a[i] == ' ') pos++;
            else if(a[pos] == 0)    a[pos] = a[i]
        }


    }
    cin >> t;
    return 0;



}
