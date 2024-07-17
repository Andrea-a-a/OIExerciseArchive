#include <iostream>
#include <math.h>
using namespace std;

double dis(long long x, long long y, long long z, long long x2, long long y2, long long z2){
    double d;
    d = sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2) + (z-z2)*(z-z2));
    return d;


}


long long X, Y, Z, x, y, z;
double maxd = 0;
int main(){
    //freopen("b5.in", "r", stdin);
    cin >> X >> Y >> Z;
    x = X;
    y = Y;
    z = Z;
    string s;
    getchar();
    getchar();
    getline(cin, s);
    for(long long i = 0; i < s.length(); i++){
        if(s[i] == 'a') z++;
        else if(s[i] == 'b'&& z > 0) z--;
        else if(s[i] == 'c')    x--;
        else if(s[i] == 'd')    x++;
        else if(s[i] == 'e')    y--;
        else if(s[i] == 'f')    y++;

        maxd = max(maxd, dis(X,Y,Z,x,y,z));

    }

    printf("%.3f",maxd);

    return 0;
}