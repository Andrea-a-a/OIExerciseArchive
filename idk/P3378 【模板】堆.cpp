#include <iostream>
using namespace std;

long long a[1000005];
int a_size=1;

void put(int d);
void pop();

int main(void){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int b;
        cin >>b;
        if(b==1)
        {
            int d;
            cin >> d;
            put(d);
        }
        else if(b==2){
            cout << (a[1]);
        }
        else if(b==3){
            pop();
        }
    }


}

void put(int d){

    int now,next;
    a_size++;
    a[a_size]=d;
    now=a_size;

    while(now>1){
        next=now/2;
        if(a[now]>=a[next]) return;
        swap(a[now],a[next]);
        now=next;
    }
}

void pop(){
    int now, next;
    swap(a[1],a[a_size]);
    a_size--;
    now=1;
    while(now*2<a_size){
        next=now*2;
        //if(next<a_size&&a[next+1]<a[next]) next++;
        if(a[now]<=a[next]) return;
        swap(a[now], a[next]);
        now=next;

    }
    return;
}


