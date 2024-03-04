//P1048 [NOIP2005 ÆÕ¼°×é] ²ÉÒ©
#include <iostream>
using namespace std;

int T, M;
int dp[1010];
int t[110], v[110];

int main(){
    //freopen("test.txt", "r", stdin);
    cin >> T >> M;
    //cout <<"miao"<<T<<"m"<<M<<endl;
    for(int i = 1; i <= M ; i++){
        cin >> t[i] >> v[i];
    }
    for(int i = 1; i <= M; i++){
        for(int o = T; o >= 0; o--){
            if(o>=t[i])dp[o] = max(dp[o],dp[o-t[i]]+v[i]);
            //else dp[o] = dp[o];
        }

    }
    cout << dp[T];
    return 0;

}
