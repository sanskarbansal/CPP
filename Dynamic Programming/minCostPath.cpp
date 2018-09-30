#include<bits/stdc++.h>
using namespace std;

int minCostPath_DP(int** input, int m, int n){
  int**ans = new int*[m];
  for(int i = 0; i < m; i++){
    ans[i] = new int[n];
  }
  ans[m-1][n-1] = input[m-1][n-1];
  for(int i = n-2; i>=0; i--){
    ans[m-1][i] = input[m-1][i] + ans[m-1][i+1];
  }
  for(int i = m-2; i>=0; i--){
    ans[i][n-1] = input[i][n-1] + ans[i+1][n-1];
  }
  for(int i = m-2; i>=0; i--){
    for(int j = n-2; j>=0; j--){
      ans[i][j] = input[i][j] + min(ans[i+1][j+1], min(ans[i][j+1], ans[i+1][j]));
    }
  }
  int an = ans[0][0];
  for(int i = 0; i < m; i++){
    delete [] ans[i];
  }
  return an;
}


int main(){
  int m, n;
  cin >>m >> n;
  int** path = new int*[m];
  for(int i = 0; i < m; i++){
    path[i] = new int[n];
    for(int j = 0; j < n; j++){
      cin >> path[i][j];
    }
  }
  cout << minCostPath_DP(path, m, n);
  for(int i = 0; i < m; i++){
    delete[] path[i];
  }
}
