//Link: https://www.spoj.com/problems/PPATH/

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

vector<bool> primes; 
vi primesTill; 
vector<vi> graph(10000); 
void sieve(){
	primes[0] = primes[1] = false; 
	for(int i = 2; i*i <= 10000; i++) if(primes[i]) for(int j = i*i; j <= 10000; j += i) primes[j] = false; 
	for(int i = 1000; i <= 10000; i++){
		if(primes[i]) primesTill.pb(i); 
	}
}
int diff(int a, int b){
	int ans = 0; 
	while(a && b){
		ans += (a%10) != (b%10); 
		a /= 10; 
		b /= 10; 
	}
	return ans; 
}

void bfs(int src, vi &visited, vi &distance){
	queue<int> q; 
	q.push(src); 
	visited[src] = 1; 
	distance[src] = 0; 
	while(!q.empty()){
		int front = q.front(); 
		q.pop(); 
		for(int x: graph[front]){
			if(!visited[x]){
				visited[x] = 1; 
				distance[x] = distance[front]+1; 
				q.push(x); 
			}
		}
	}

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t; 
	cin >> t; 
	primes.resize(10000, true); 
	sieve(); 
    //Make a graph of all primes who differs by one digit and connect them. Why 1? because at most change in digit can be one and we can change digits one by one. 
	for(int u: primesTill){
		for(int v: primesTill){
			if(u != v && diff(u, v)==1){
				graph[u].pb(v); 
			}
		}
	}

	while(t--){
		vi visited(10000, 0); 
		vi distance(10000, 0); 
		int a, b; 
		cin >> a >> b; 
		bfs(b, visited, distance); //Simply apply the dfs from a or b.
		if(!visited[a]){
			cout << "Impossible\n"; 
		}
		else{
			cout << distance[a] << endl; 
		}
	} 
}