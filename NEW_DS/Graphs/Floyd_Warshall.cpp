#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
#define pb push_back
typedef long long ll;

vector<vi> graph; 
vector<vi> shortestPath; 

void floydWarshall(int n, int e){
    
    rep(k, n){
        rep(i, n){
            rep(j, n){
                if(shortestPath[i][k]==INT_MAX || shortestPath[k][j]== INT_MAX) continue; 
                shortestPath[i][j] = min(shortestPath[i][j], shortestPath[i][k] + shortestPath[k][j]); 
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int v, e; 
    cin >> v >> e; 
    graph.resize(v); 
    shortestPath.resize(v); 
    rep(i, v){
        graph[i].resize(v, INT_MAX); 
        shortestPath[i].resize(v, INT_MAX); 
    }
    rep(i, v){
        graph[i][i] = 0; 
        shortestPath[i][i] = 0; 
    }
    rep(i, e){
        int u, v, w; 
        cin >> u >> v >> w; 
        graph[u][v] = w;   
        shortestPath[u][v] = w;       
    }
    floydWarshall(v, e); 
    rep(i, v){
        rep(j, v){
            cout << shortestPath[i][j] << "\t"; 
        }
        cout << endl; 
    }
}