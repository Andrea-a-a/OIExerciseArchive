#include <iostream>
using namespace std;
//憨憨线段树 非常朴素！

int gcd(int a, int b){
    if(a%b == 0)    return b;
    return gcd(b, a%b);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << "heelloworld!" << endl;
    int o = gcd(a,b);
    cout << a+b << endl << o;
}