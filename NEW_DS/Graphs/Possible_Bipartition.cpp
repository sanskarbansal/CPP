//Porblem Link: https://leetcode.com/problems/possible-bipartition/
//Difficulty Level: Medium; 
//Concept Used: BFS, Bipartite Graph, Colouring Graph
#include<bits/stdc++.h>
using namespace std; 

class Solution {
    bool bfs(vector<vector<int>> &adjList, int N){
        vector<int> colors(N+1, -1); 
        for(int i = 1; i <= N; i++){
            if(colors[i]==-1){
                queue<int> q; 
                q.push(i); 
                colors[i] = 0; 
                while(!q.empty()){
                    int front = q.front(); q.pop(); 
                    int len = adjList[front].size(); 
                    for(int j = 0; j < len; j++){
                        if(colors[adjList[front][j]] == colors[front])return false; 
                        if(colors[adjList[front][j]]==-1){
                            colors[adjList[front][j]] = colors[front]^1; 
                            q.push(adjList[front][j]); 
                        }
                    }
                }
            }
        }
        return true; 
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(N+1); 
        for(int i = 0; i < dislikes.size(); i++){
            int u = dislikes[i][0], v = dislikes[i][1]; 
            adjList[u].push_back(v); 
            adjList[v].push_back(u); 
        }
        return bfs(adjList, N); 
        
    }
};