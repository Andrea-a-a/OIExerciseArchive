//这玩意怎么能出到2啊？？？？？？？？？？？？？
#include <iostream>
using namespace std;

int main(){
    freopen("1.lrc", "r", stdin);
    freopen("1ex-wife.lrc", "w", stdout);
    string a;
    int i = 0;
    do
    {
        a = "";
        getline(cin, a);
        i++;
        if(i%2 == 1){
            cout << a << endl;
        }

    } while (a != "");
    



}