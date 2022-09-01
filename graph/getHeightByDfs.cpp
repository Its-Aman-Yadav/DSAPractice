#include <bits/stdc++.h>
using namespace std;

vector<bool>Visited(1e6);
void printDfs(vector<vector<int>>Adj, int i){
	cout<<i<<" ";
	for(auto a:Adj[i]){
		if(!Visited[a]) {
			Visited[a] = 1;
			printDfs(Adj,a);
		}
	}
	
}

int getHeight(vector<vector<int>>Adj, int i){
	int height = 1;
	Visited[i] = 1;
	for(auto a:Adj[i]){
		if(!Visited[a]) {
			height= max(height,1+getHeight(Adj,a));
		}
	}
	return height;
}
// i= 1

vector<vector<int>>getAdjecencyList(vector<vector<int>>Edges, int n){
	//n is number of nodes
	vector<vector<int>>Adj(n+1);
	for(auto edge : Edges){
		//edge[0], edge[1]
		Adj[edge[0]].push_back(edge[1]);
		Adj[edge[1]].push_back(edge[0]);
	}
	
	//printing Adj Matrix
	// for(int i=0;i<=n;i++){
	// 	cout<<"i: "<<i<<"\n";
	// 	cout<<"   ";
	// 	for(auto a:Adj[i]) cout<<a<<" ";
	// 	cout<<"\n";
	// }
	return Adj;
}
int main() {
	vector<vector<int>>Edge = {{1,4},{1,2},{4,8},{4,9},{1,5},{5,7},{2,3},{2,6},{8,10}};
	auto Adj= getAdjecencyList(Edge, 10);
	Visited[1] = 1;
	//printDfs(Adj,1);
	cout<<"height: "<<getHeight(Adj,1)<<"\n";
	return 0;
}
