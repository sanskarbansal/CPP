//Link to the problem: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
//Concepts: BFS, BFS. 
#include<bits/stdc++.h>
using namespace std; 

class Solution {
    void dfs(vector<vector<int>> &graph, vector<int> &visited, int src){
        visited[src] = true; 
        int x = graph[src].size(); 
        for(int i = 0; i < x; i++){
            if(!visited[graph[src][i]]) dfs(graph, visited, graph[src][i]); 
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size(); 
        if(edges < n-1) return -1; 
        vector<vector<int>> graph(n); 
        for(int i = 0; i < connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]); 
            graph[connections[i][1]].push_back(connections[i][0]); 
        }
        int ans = 0; 
        vector<int> visited(n, false); 
        for(int i = 0; i < n; i++){
            if(visited[i]) continue; 
            dfs(graph, visited, i); 
            ans++; 
        }
        return ans-1; 
    }
};