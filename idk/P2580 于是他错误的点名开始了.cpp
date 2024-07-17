// P2580 于是他错误的点名开始了
#include <iostream>
#include <map>
#include <string>

using namespace std;
map<string, int> name;

int main(){
	int n, m;
	cin >> n;
	for(int o = 0; o < n; o++){
		string a;
		cin >> a;
		name.insert(make_pair(a, 0));
	}
	cin >> m;
	for(int p = 0; p < m; p++){
		string b;
		cin >> b;
		if(name.count(b) && name[b] == 0){
			name[b]++;
			cout << "OK" <<endl;
		}
		else if(name.count(b)){
			cout << "REPEAT"<<endl;
		}
		else if(!name.count(b)){
			cout << "WRONG"<<endl;
		}
	}
}
