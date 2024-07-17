#include <iostream>
#include <queue>

using namespace std;
long long p = 0;
int e[1001];
int now = 0;

int main(){
    int n, a, temp;
    cin >> n >> a;

    for(int i = 0; i < a; i++){
        int test = 0;
        cin >> temp;
        for(int s = 0; s < n; s++){
            if(temp == e[s]) test++;
        }
        if(test == 0){
        e[now%n] = temp;
        now++;
        p++;
        int u = 0;
        for(int s = 0; s < n; s++){
            cout << "e[" << s << "] ==" << e[s] << " || ";
            
			u++;
            if(u%5 == 0)
            {
            	cout<<endl;
			}
                }
        
        }
        
        
        cout<<endl; 

        
        
    }
    cout<<p;
    

}


