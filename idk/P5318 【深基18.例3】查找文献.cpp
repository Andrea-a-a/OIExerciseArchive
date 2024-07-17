//P5318 【深基18.例3】查找文献
//思路：邻接表存图->DFS和BFS->排序
//排序：vector排序 sort(name.begin(), name.end());  需要#include <algorithm> 
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

vector<int> A[100010];//邻接表 
queue<int> B;
bool visited[100010]; 
int n, m; //n个点 m个边 

void dfs(int x, int num);
void bfs(int x);

int main(){
	scanf("%d %d", &n, &m);
	int u, v;
	for(int i = 1; i <= m; i++){
		scanf("%d %d",&u,&v);
		A[u].push_back(v);
	}
	for(int i = 1; i <= n; i++)	sort(A[i].begin(), A[i].end());
	dfs(1, 0);
	printf("\n");
	bfs(1);
	printf("\n");
	return 0;
}

void dfs(int x, int num){
	visited[x] = true;
	printf("%d ", x);
	if(num == n) return;
	for(int i = 0; i < A[x].size(); i++){
		if(visited[A[x][i]] == false) dfs(A[x][i], num+1);
	}
}

void bfs(int x){
	memset(visited, false, sizeof(visited));
	visited[x] = true;
	B.push(x);
	while (!B.empty()){
		int o = B.front();
		B.pop();
		printf("%d ", o);
		for(int i = 0; i < A[o].size(); i++){
			if (!visited[A[o][i]]){
				visited[A[o][i]] = true;
				B.push(A[o][i]);
			}
		}
	}
	
}

/*** 今天学到了什么：
	bool数组的初始值是false
	scanf和printf怎么用 需要#include<cstdio>
	dfs用递归 
	bfs用queue 可以看看深入浅出p194 
	memset 需要#include <string.h> 
***/ 
