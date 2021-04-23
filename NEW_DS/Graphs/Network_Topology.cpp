//Link: http://codeforces.com/problemset/problem/292/B
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


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m; 
	cin >> n >> m; 
	vector<vi> graph(n+1); 
	vector<int> degrees(n+1, 0); 
	rep(i, m){
		int u, v; 
		cin >> u >> v; 
		graph[u].pb(v); 
		degrees[u]++; 
		degrees[v]++; 
		graph[v].pb(u); 
	}
	sort(degrees.begin(), degrees.end()); 
	if(degrees[1]==2 && degrees[n]==2){
		cout << "ring topology"; 
	}else if(degrees[1]==1 && degrees[2]==1 && degrees[3]==2 && degrees[n]==2){
		cout << "bus topology"; 
	}else if(degrees[1] == 1 && degrees[n-1]==1 && degrees[n]==n-1){
		cout << "star topology"; 
	}else{
		cout << "unknown topology"; 
	}
}