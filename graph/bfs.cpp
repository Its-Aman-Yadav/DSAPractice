#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>Adj, int u){
	queue<int>Q;
	Q.push(u);
	vector<bool>Visited(Adj.size());
	Visited[u]=1;
	while(!Q.empty()){
		int front = Q.front();
		cout<<front<<" ";
		Q.pop();
		
		for(auto v:Adj[front]){
			if(Visited[v]) continue;
			Visited[v]=1;
			Q.push(v);
		}
	}
}
void printBfs(vector<vector<int>>Edge, int n){
	vector<vector<int>>Adj(n+1);
	for(auto edge:Edge){
		Adj[edge[0]].push_back(edge[1]);
		Adj[edge[1]].push_back(edge[0]);
	}
	// 1-> 4, 2
	
	bfs(Adj, 1);
}
int main() {
	printBfs({{1,4},{1,2},{4,5},{2,3},{3,6}}, 7);
	return 0;
}
