#include<iostream>
#include<vector>
using namespace std;
#define ll long long

ll fib(ll &n){
  vector<ll> f;
  f.push_back(0); f.push_back(1);
  for(ll i = 2; i <=n; i++){
    f.push_back(f[i-1] + f[i-2]);
  }
  return f.at(n);
}

int main(){
  ll n;
  cin >> n;
  cout << fib(n);
}
