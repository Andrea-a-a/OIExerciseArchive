//idk
#include <iostream>
using namespace std;

int main(){
    freopen("guns-c1.lrc", "r", stdin);
    freopen("guns-c2.lrc", "w", stdout);
    int check = 4;
    int cnt = 0;
    string a;
    string b = "[mm:00]";
    string c;
    do{
        a = "";
        getline(cin, a);
        cnt++;
        if(check == 1){
            if (cnt % 2 == 0)
        {
            cout << a << endl;
        }
        }
        else if(check == 0){
            if (cnt % 2 == 0){
                for(int i = 0; i < 7; i++){
                    b[i] = a[i];
                }
                //cout << a << endl;
                //cout << b << endl;
            }
            else{
                for(int i = 0; i < 7; i++){
                    a[i] = b[i];
                }
                // for(int i = 4; i < a.length(); i++){
                //     cout << a[i];
                // }
                // cout << endl;
                cout << a << endl;
            }

        }
        else {
            a[0] = ':';
            a[3] = '.';
            c = "[00" + a;
            swap(c[2], c[5]);
            c[4] = c[7];
            c[5] = c[8];
            c[7] = '0';
            c[8] = '0';
            cout << c << endl;

        }
        


    }while(a != "");
    return 0;




}