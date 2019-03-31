#include<bits/stdc++.h>
using namespace std;
#define pb push_back
map<int, vector<int> > adj; 
vector<bool> vis;
vector<pair<int, int> > dis;
void bfs(int src){
	queue<int> q; 
	q.push(src);
	dis[src].first = 0, dis[src].second = src;
	vis[src] = 1;
	while(!q.empty()){
		int u = q.front(); 
		q.pop();
		for(auto x: adj[u]){
			if(vis[x] == false){
				q.push(x);
				dis[x].first = dis[u].first + 1;
				dis[x].second = u;  
				vis[x] = 1;
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cout << "Enter number of vertices: "; cin >> n; 
	cout << "\nEnter number of edges: "; cin >> m; 
	vis.resize(n+1, false);
	dis.resize(n+1); 
	cout << "\nEnter edges: \n";
	int u, v; 
	for(int i = 0; i < m; i++){
		cin >> u >> v; 
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int src; 
	cout << "\nEnter source vertex: " ; cin >> src; 
	bfs(src);
	for(int i = 1; i < n; i++){
		cout << "\nDistance of " << i << " from " << src << " is: " << dis[i].first << " and parent of " << i << " is " << dis[i].second;
	}
}
