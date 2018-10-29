#include<bits/stdc++.h>
using namespace std;

bool hasPath_helper(map<int, int*> &adjList, int V, int sv, int ev, bool *visited){
	if(adjList[sv][ev] == 1){
		return true;
	}
	visited[sv] = 1;
	for(int i = 0; i < V; i++){
		if(i == sv){
			continue;
		}
		if(adjList[sv][i] == 1 && visited[i] == false){
			bool small = hasPath_helper(adjList, V, i, ev, visited);
			visited[i] = 1;
			if(small){
				return true;
			}
		}
	}
	return false;
}

bool hasPath(map<int, int*> &adjList,int vert, int v, int u){
	bool visited[vert] = {0};
	return hasPath_helper(adjList,vert, v, u, visited);
}

int main(){
	int V, E;
	cin >> V >> E;
	map<int, int*> adjList;
	for(int i  = 0; i < V; i++){
		adjList[i] = new int[V]{0};
	}
	for(int i = 1; i <= E; i++){
		int x, y;
		cin >> x >> y;
		adjList[x][y] = 1;
		adjList[y][x] = 1;
	}
	int v, u;
	cin >> v >> u;
	hasPath(adjList, V, v, u)?(cout << "True"):(cout << "False");
}
