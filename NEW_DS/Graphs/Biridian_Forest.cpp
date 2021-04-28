//Link: https://codeforces.com/contest/329/problem/B


#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()


typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

vector<vector<char>> grid; 
vector<vi> visited; 
vector<vi> distances; 
int ex, ey; 
int dx[] = {-1, 1, 0, 0}; //Lef Right
int dy[] = {0, 0, -1, 1}; //Down Up
int n,m ; 


//Check if cell is visited, or there exists a Tree on that cell or the indexes are out of bound. 
bool isValid(int x, int y){
	if(x < 0 || y < 0 || x >= m || y >= n || visited[y][x] || grid[y][x]=='T') return false; 
	return true; 
}

//BFS on the Exit Cell so that we can get path from exit to every cell. 
void bfs(int ex, int ey){
	queue<pii> q; 
	q.push({ex, ey});
	distances[ey][ex] = 0; 
	visited[ey][ex] = 1; 
	while(!q.empty()) {
		pii front = q.front(); 
		int x = front.fi; 
		int y = front.se; 
		q.pop(); 
		rep(i, 4){
			int ny = dy[i] + y; 
			int nx = dx[i] + x; 
			if(isValid(nx, ny)){
				visited[ny][nx] = 1; 
				distances[ny][nx] = distances[y][x]+1; 
				q.push({nx, ny}); 
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin >> n >>m ; 
	int sx , sy; 
	grid.resize(n, vector<char>(m)); 
	visited.resize(n, vi(m, 0));
	distances.resize(n, vi(m, INT_MAX));

	rep(i, n) 
	rep(j, m){
		cin >> grid[i][j]; 
		if(grid[i][j]=='S'){
			sx = j; 
			sy = i; 
		}
		if(grid[i][j]=='E'){
			ex = j; 
			ey = i; 
		}
	}
	bfs(ex, ey); 
	int distance = distances[sy][sx]; 
	int ans = 0; 
	rep(i, n){
		rep(j, m){ 
			int d = grid[i][j] - '0'; 
			if( d > 0 && d <= 9 && distances[i][j] <= distance){
				ans += d; //If breedier can reach to E cell faster than us than definately it'll attack us. 
			}
		}
	}
	cout << ans; 
}