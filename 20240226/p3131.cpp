//p3131
/*给你n个数,分别是a[1],a[2],...,a[n]。求一个最长的区间[x,y]，使得区间中的数(a[x],a[x+1],a[x+2],...,a[y-1],a[y])的和能被7整除。
  输出区间长度。若没有符合要求的区间,输出0。*/
/*记录前缀和mol7 不同余数的第一次和最后一次出现位置*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+10;
int sum;
int first[7], last[7];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < 7; i++){
        first[i] = 1e5;
        last[i] = -1;
    }
    first[0] = 0;
    /* 所以,对于从头加到i是7的倍数的情况下，需要把余数为0第一次出现的位置设为0，才能让程序认为是把整个区间[1,i]选上了。*/
    for(int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        sum = (sum+temp) % 7;
        //cout << "i = :" << i << " sum : " << sum <<  endl;
        if(first[sum] == 1e5)   first[sum] = i;
        last[sum] = max(last[sum], i);
    }
    int ans = 0;
    for(int i = 0; i < 7; i++){
        ans = max(ans, last[i]-first[i]);
        //cout << "i = " << i << " first:" << first[i] << " last:" << last[i] << endl;
    }
    cout << ans;

    return 0;
}