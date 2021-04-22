//Link: https://leetcode.com/problems/is-graph-bipartite/
//Difficulty: Medium (According to leetcode but it easy)
//Concepts Used: BFS, DFS, Bipartite Graph, Graph Colouring. 
#include<bits/stdc++.h>
using namespace std; 

//Using BFS; 
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> color(n, -1); 
        for(int i = 0; i < n; i++){
            if(color[i]==-1){
                queue<int> q; 
                q.push(i); 
                color[i] = 0; 
                while(!q.empty()){
                    int u = q.front(); q.pop(); 
                    int len = graph[u].size();
                    for(int v = 0; v < len; v++){
                        if(color[u]==color[graph[u][v]]) return false; 
                        if(color[graph[u][v]] == -1){
                            color[graph[u][v]] = color[u]^1; 
                            q.push(graph[u][v]); 
                        }
                    }
                }
            }
        }
        return true; 
    }
};

//USing DFS; 
class Solution {
    
    bool dfs(vector<vector<int>> &graph, int src, vector<int> &colors){
        int n  = graph[src].size(); 
        for(int i = 0; i < n; i++){
            if(colors[graph[src][i]] == -1){
                colors[graph[src][i]] = colors[src]^1; 
                if(!dfs(graph, graph[src][i], colors)) return false; 
            }
            if(colors[graph[src][i]] == colors[src]) return false; 
        }
        return true; 
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> colors(n, -1); 
        for(int i = 0; i < n; i++){
            if(colors[i]!=-1) continue; 
            if(!dfs(graph, i, colors)) return false; 
        }
        return true; 
    }
};