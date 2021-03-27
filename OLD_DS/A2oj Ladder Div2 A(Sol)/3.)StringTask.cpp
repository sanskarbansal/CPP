#include<bits/stdc++.h>
using namespace std;

bool vovel(string input){

  return true;
}

string ladder(string input){
  if(input.empty()){
    return "";
  }
  string small = ladder(input.substr(1));
  if(input[0] <= 96 && input[0] >= 65){
    input[0] = input[0]+32;
  }
  if(input[0] == 'A'
   || input[0] == 'a'
   || input[0] == 'E'
   || input[0] == 'e'
   || input[0] == 'I'
   || input[0] == 'i'
   || input[0] == 'O'
   || input[0] == 'o'
   || input[0] == 'U'
   || input[0] == 'u'
   || input[0] == 'Y'
   || input[0] == 'y'){
   input = small;
 }else{
    string temp = ".";
    temp = temp + input[0] + small;
    input = temp;
  }
  return input;
}

int main() {
  string t;
  cin >> t;
  cout << ladder(t);
  return 0;
}