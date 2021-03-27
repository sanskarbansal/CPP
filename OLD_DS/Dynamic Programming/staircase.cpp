#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll staircase(ll n){
  vector<ll> s;
  s.push_back(1);s.push_back(1);s.push_back(2);
  for(ll step = 3; step<= n; step++){
    s.push_back(s[step-1]+s[step-2]+s[step-3]);
  }
  return s[n];
}

int main(){
  ll n;
  cin >> n;
  cout << staircase(n);
}
