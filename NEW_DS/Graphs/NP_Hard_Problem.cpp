/*
Link to the problem: https://codeforces.com/contest/687/problem/A
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
#define pb push_back
typedef long long ll;

vector<vector<int>> graph; 
vector<int> colors, a, b; 
int n; 
bool colorGraph(int src){
    if(graph[src].size()==0)return true; 
    queue<int> q; q.push(src); 
    colors[src] = 1; b.pb(src+1); 
    while(!q.empty()){
        int front = q.front(); q.pop(); 
        for(int x: graph[front]){
            if(colors[x]==colors[front]){
                return false; 
            }
            if(colors[x] == 0){
                q.push(x); 
                colors[x] = 3-colors[front]; // why 3? because 2+1=3; 
                if(colors[x] == 1) b.pb(x+1); 
                else a.pb(x+1); 
            }
        }
    }
    return true; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int m; 
    cin >> n >> m; 
    graph.resize(n); 
    colors.resize(n, 0); 
    rep(i, m){
        int u, v; 
        cin >> u >> v; 
        u--; v--; 
        graph[u].pb(v); 
        graph[v].pb(u); 
    }
    for(int i = 0; i < n; i++){
        if(colors[i]==0 && !colorGraph(i)){
            cout << -1; 
            return 0; 
        }
    }
    cout << a.size() << endl; 
    for(int x: a) cout << x << " "; 
    cout << endl << b.size() << endl;
    for(int x: b) cout << x << " ";      
    
}