//P1002 [NOIP2002 普及组] 过河卒
#include <iostream>


using namespace std;

long long a[21][21];
int flag[21][21];
int step[8][2] = { {1, 2}, {1, -2}, {2, -1}, {2, 1}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1} };

int main(){
	int bx, by, ax, ay;
    scanf("%d %d %d %d", &bx, &by, &ax, &ay);
    //by++; bx++; ax++; ay++;
    //cout << bx<< by<< ax<< ay<< endl;
    flag[ax][ay] = 1;
    for(int o = 0; o < 8; o++){
        int tx, ty;
        tx = ax + step[o][0];
        ty = ay + step[o][1];
        //cout << " "<<tx << ty<<endl;
        if (tx >= 0 && ty >= 0 && tx <=bx && ty <= by){
            flag[tx][ty] = 1;
        }
    }
    //a[1][1] = 1;
    for(int i = 0; i <=bx; i++){
        for (int j = 0; j <= by; j++){
            if (flag[i][j] == 0){
                if (i == 0&& j == 0) a[i][j] = 1;
                else if(i == 0) a[i][j] = a[i][j-1];
                else if(j == 0) a[i][j] = a[i-1][j];
                else a[i][j] = a[i-1][j] + a[i][j-1];
            }
            
            
            //cout <<"i: " << i << " j: "<<j << " a " << a[i][j]<< endl;
        }
    }

    cout << a[bx][by];
    return 0;
}
