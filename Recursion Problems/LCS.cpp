#include<bits/stdc++.h>
using namespace std;

int LCS(string t, string s){
  if(t.empty() || s.empty()){
    return 0;
  }
  if(t[0] == s[0]){
    return 1 + LCS(t.substr(1), s.substr(1));
  }
  int x = LCS(t, s.substr(1));
  int y = LCS(t.substr(1), s);
  return max(x, y);
}

int main(){
  string s, t;
  cin >> s >> t;
  cout << LCS(s, t);
}
