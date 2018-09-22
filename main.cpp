#include<iostream>
#include<vector>
#include<string>
#include "Trie.h"
using namespace std;

int main() {
  Trie he;
  vector<string> v;
  for(int i = 0; i < 378; i++){
    string temp;
    cin >> temp;
    v.push_back(temp);
  }
  cout << "Enter The Word You Want To Search: ";
  string temp;
  cin >> temp;
  he.autoComplete(v, temp);
  return 0;
}
