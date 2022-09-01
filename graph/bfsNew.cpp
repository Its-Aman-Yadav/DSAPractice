#include <bits/stdc++.h>
using namespace std;

void printBfs(vector<vector<int>>Adj, int i){
	queue<int>Q;
	Q.push(i);
	vector<bool>Visited(Adj.size()); //if pushed in queue then don't push it again
	Visited[i]=1;
	while(!Q.empty()){
		int front = Q.front();
		cout<<front<<" ";
		Q.pop();
		for(int a:Adj[front]){
			if(!Visited[a]) {
				Q.push(a);
				Visited[a]=1;
			}
		}
	}
}

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
	printBfs(Adj,1);
	return 0;
}
