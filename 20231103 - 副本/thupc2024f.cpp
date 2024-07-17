#include <bits/stdc++.h>
using namespace std;

int n, m, k;
const int MAXN = 105, MAXM = 11;
int l[MAXN], r[MAXN];
char a[MAXN][MAXM];
int b[MAXN][MAXM][3];
string repl[1010];
int cntrep = 0;
string trig[1010][2];
int cnttri = 1;

void input(string s, int id, int i);

void slackoff(int id){
    cout << "Robot "<<id << " slacks off."<<endl;
}

void move(int id, int h, int i){
    if(h == 0){
        l[id] = (l[id] + i )%n;
        cout << "Robot " << id << " moves its "<<"left"<<" hand towards Robot "<<l[id]<<"."<<endl;
    }
    else{
        r[id] = (r[id] + i )%n;
        cout << "Robot " << id << " moves its "<<"right"<<" hand towards Robot "<<r[id]<<"."<<endl;
    }
    
}

void swapp(int h, int x, int y, int id){
    int id2;
    if(h == 0){
        id2 = l[id];
    }
    else{
        id2 = r[id];
    }
    swap(a[id2][x],a[id][y]);
        swap(b[id2][x][0], b[id][y][0]);
        swap(b[id2][x][1], b[id][y][1]);
        swap(b[id2][x][2], b[id][y][2]);
cout << "Robot " << id << " swaps a line of command with Robot " <<id2<<endl;

}

void mirror(int id, int h, int x){
    int id2;
    if(h == 0){
        id2 = l[id];
    }
    else{
        id2 = r[id];
    }
    if(b[id2][x][0] == 0) b[id2][x][0]=1;
    else b[id2][x][0] = 0;
    cout <<  "Robot " << id << " modifies a line of command of Robot " << id2 << "."<<endl;
}

int main(){
    freopen("2.in", "r", stdin);
    cin >>  n >> m>>k;
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
        getchar();
        for(int o = 0; o < m; o++){
            string s;
            getline(cin,s);
            //getchar();
            //cout << s << endl;
            input(s, i, o);
        }

    }
    int cnt = 0, id = 0;
    while(cnt < k){
        for(int w = 0; w< m; w++){
            if(a[id][w] == 'L')  {slackoff(id);cnt++;}
            else if(a[id][w] == 'O')    {move(id, b[id][w][0], b[id][w][1]);cnt++;}
            else if(a[id][w] == 'W')    {swapp(b[id][w][0],b[id][w][1],b[id][w][2],id);cnt++;}
            else if(a[id][w] == 'I')    {mirror(id, b[id][w][0], b[id][w][1]);cnt++;}
        }
        id = (id+1)%n;
    }
    //for(int i = 0; i < 5; i++) cout << trig[i][0] << "miao " << trig[i][1]<<endl;
}

void input(string s, int id, int i){
    if(s[0] == 'S' && s[1] == 'L')  a[id][i] = 'L'; 
    else if(s[0] == 'M' && s[1] == 'O'){
        a[id][i] = 'O';
        b[id][i][0] = s[5];
        b[id][i][1] = s[7];
    }
    else if(s[1] == 'W'){
        a[id][i] = 'W';
        b[id][i][0] = s[5];
        b[id][i][1] = s[7];
        b[id][i][2] = s[9];
    }
    else if(s[1] == 'I'){
        a[id][i] = 'I';
        b[id][i][0] = s[7];
        b[id][i][0] = s[9];
    }
    else if(s[1] == 'E'){
        a[id][i] = 'E';
        b[id][i][0] = s[8];
        b[id][i][1] = s[10];
        b[id][i][2] = cntrep;
        cntrep++; 

    }
    else if(s[1] == 'C' ){
        a[id][i] = 'C';
        b[id][i][0] = s[9];
    }
    else if(s[1] == 'R'){
        a[id][i] = 'R';
        trig[cnttri][0] = s[9];
        int colon = -1;
        trig[cnttri][1] = s;
        for(int p = 0; p < s.length(); p++){
            if(s[p] == ':') colon = p;
            else if(colon != -1)    trig[cnttri][1][p-colon-2] = s[p];
            //cout <<s.length()<<" colom"<< colon << endl; 
            //if(p-colon < p) trig[cnttri][1][p-colon] = ' ';
        }
        cnttri++;
    }

}
