#include<bits/stdc++.h>
using namespace std;
string SB = "SANSKARBANSAL";
bool **visited;
bool helper(char **mat, int n, int m, int i , int j, int x = 0){
  if(x == 13){
    return true;
  }
  if(i < 0 || i >= n || j < 0 || j >= m || mat[i][j] != SB[x] || visited[i][j])
    return 0;

  if(mat[i][j] == SB[x]){
    visited[i][j] = 1;
  	bool d1 = helper(mat, n, m, i, j+1, x+1);
  	bool d2 = helper(mat, n, m, i, j-1, x+1);
  	bool d3 = helper(mat, n, m, i+1, j, x+1);
  	bool d4 = helper(mat, n, m, i-1, j, x+1);
  	bool d5 = helper(mat, n, m, i+1, j+1, x+1);
  	bool d6 = helper(mat, n, m, i-1, j-1, x+1);
  	bool d7 = helper(mat, n, m, i+1, j-1, x+1);
  	bool d8 = helper(mat, n, m, i-1, j+1, x+1);
    return (d1 || d2 || d3 || d4 || d5 || d6 || d7 || d8);
  }
}

int solve(char **Graph,int N, int M)
{
  visited = new bool*[N];
  for(int i = 0; i < N; i++){
    visited[i] = new bool[M]{0};
  }
  int i, j;
  for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      if(Graph[i][j] == 'S'){
        if(helper(Graph, N, M, i, j)) return 1;
      }
    }
  }
  return 0;
}

int main(){
    int n, q;
    cin >> n >> q;
    char**graph = new char*[n];
    for(int i =0; i < n; i++){
        graph[i] = new char[q];
        for(int j= 0; j< q;j++){
         cin>>graph[i][j];
        }
    }
    if(solve(graph, n, q)){
        cout << "Yes Path Exists\n";
    }else{
        cout<<"Path Does Not Exists\n";
    }
}
/* 

Given a NxM matrix containing Uppercase English Alphabets only. 
Your task is to tell if there is a path in the given matrix which makes the sentence "SANSKARBANSAL" .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner

Input:
n, m
n number of lines containing m characters
Output:
Yes Path Exists|| Path Does Not Exists


Input1:
2 9
SAXSXABNA
XXNXKRASL

Output1:
Yes Path Exists


Input2:
2 9
SAXSXABNA
XXNXKRASL

Output2:
Path Does Not Exists



*/
