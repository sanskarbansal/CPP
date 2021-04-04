/*
Link to problem: http://codeforces.com/problemset/problem/295/B
Algorithm Used: Floyd warshell. 
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
#define pb push_back
typedef long long ll;

vector<vi> graph; 
vi sq; 
vector<ll> sum; 

void floydWarshall(int n){
    vector<bool> usableNodes(n+1, false);   
    for(int k = 1; k<= n; k++){
        int x = sq[k]; 
        usableNodes[x] = true; 
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= n; j++){
                if(graph[i][x] != 0 && graph[x][j]!= 0){
                    graph[i][j] = min(graph[i][j], graph[i][x] + graph[x][j]); 
                }
                if(usableNodes[i] && usableNodes[j]){
                    sum[k] += graph[i][j];  
                }
            }
        }
    }
    for(int i = n; i>= 1; i--) cout << sum[i] << " "; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; 
    cin >> n; 
    graph.resize(n+1);
    sq.resize(n+1); 
    sum.resize(n+1, 0); 
    for(int i = 1; i <= n; i++) graph[i].resize(n+1); 
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> graph[i][j]; 

    for(int i = n; i>= 1; i--){
        cin >> sq[i]; 
    } 
    floydWarshall(n); 
    return 0; 
}