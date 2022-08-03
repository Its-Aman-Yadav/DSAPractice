#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>Adj, int u, vector<bool>&V){
	cout<<u<<" ";
	for(auto v:Adj[u]){
		if(V[v]){
			continue;
		}
		V[v]=1;
		dfs(Adj,v,V);
	}
}
void printDfs(vector<vector<int>>Edge, int n){
	vector<vector<int>>Adj(n+1);
	for(auto edge:Edge){
		Adj[edge[0]].push_back(edge[1]);
		Adj[edge[1]].push_back(edge[0]);
	}
	vector<bool>Visited(n+1);
	Visited[1] = 1;
	dfs(Adj, 1, Visited);
}
int main() {
	printDfs({{1,4},{1,2},{2,3},{4,5}}, 5);
	return 0;
}
