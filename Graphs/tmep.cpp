#include<bits/stdc++.h>
using namespace std;

void bits(int n, vector<int> &arr){
  while(n){
    arr.push_back(n&1);
    n = n >> 1;
  }
}

int main(){
  cout << endl;
  int b = 2^4;
  cout << b;
  int n;
  cin >> n;
  vector<int> q;
  bits(n,q);
  int j = q.size()-1;
  while(j>=0){
    cout << q[j];
    j--;
  }
}
