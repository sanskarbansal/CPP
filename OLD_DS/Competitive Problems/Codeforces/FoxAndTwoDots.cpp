#include<bits/stdc++.h>
using namespace std;
int n, m;
char **graph;
int **visited;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void res(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j]=0;
		}
	}
}

bool helper(int sy, int sx, int i, int j, int c=1){
	visited[i][j]=1;

	if((graph[sy][sx]!=graph[i][j])){
		return false;
	}
	for(int l=0;l<4;l++){
		int nx = j+dx[l];
		int ny = i+dy[l];
	    if((sy==ny&&sx==nx)&&(c>=4)){
		    return true;
	    }
		if(((nx >= 0&&nx<m)&&(ny>=0&&ny<n))&&visited[ny][nx]==0){
			bool flag = helper(sy,sx,ny, nx,c+1);
		    if(flag){
			    return true;
		    }
		}
	}
	return false;
}

bool isCycle(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(helper(i, j, i, j)){
				return true;
			}
			res();
		}
	}
	return false;
}

int main(){
	cin>>n>>m;
	graph=new char*[n];
	visited = new int*[n];
	for(int i=0;i<n;i++){
		graph[i]=new char[m];
		visited[i]=new int[m];
		for(int j=0;j<m;j++){
			visited[i][j]=0;
			cin>>graph[i][j];
		}
	}
	if(isCycle()){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
	return 0;
}
