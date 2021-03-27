#include<bits/stdc++.h>
using namespace std;

void getPath(int** adjList, vector<int> &path, int v, int sv, int ev){
    queue<int> in;
    bool visited[v] = {0};
    map<int,int> arr;
    in.push(sv);
    visited[sv] = 1;
    while(!in.empty()){
        int frnt = in.front();
        in.pop();
        for(int i = 0; i < v; i++){
            if(i == frnt){
                continue;
            }
            if(!visited[i]){
                if(adjList[frnt][i] == 1){
                    in.push(i);
                    arr[i] = frnt;
                    visited[i] = 1;
                    if(i == ev){
                    	break;
                    }
                }
            }
        }
    }
    if(visited[ev] == true){
        while(ev != sv){
    	    path.push_back(ev);
    	    ev = arr[ev];
        }
        path.push_back(sv);
    }
}

int main(){
	int v, e;
	cin >> v >> e;
	int** adjList = new int*[v];
	for(int i = 0; i < v; i++){
		adjList[i] = new int[v]{0};
	}
	for(int i = 1; i <= e; i++){
		int x, y;
		cin >> x >> y;
		adjList[x][y] = 1;
		adjList[y][x] = 1;
	}
	int sv, ev;
	cin >> sv >> ev;
	vector<int> path;
	getPath(adjList, path, v, sv, ev);
    for(int x: path){
        cout << x << " ";
    }
}
