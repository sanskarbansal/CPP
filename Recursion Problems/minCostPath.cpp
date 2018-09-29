#include<bits/stdc++.h>
using namespace std;

int helper(int **path, int m, int n, int i, int j){
  if(i >= m || j >= n ){
    return INT_MAX;
  }
  if(i== m-1 && j == n-1){
    return path[i][j];
  }
  int x = helper(path, m, n, i, j+1);
  int y = helper(path, m, n, i+1, j+1);
  int z = helper(path, m, n, i+1, j);
  return min(x, min(y,z)) + path[i][j];
}

int minCostPath(int **input, int m, int n){
  return helper(input, m, n, 0, 0);
}

int main(){
  int m, n;
  cin >> m >> n;
  int ** path = new int*[m];
  for(int i = 0; i < m; i++){
    path[i] = new int[n];
    for(int j = 0; j < n; j++){
      cin >> path[i][j];
    }
  }
  cout << minCostPath(path, m, n);
}
