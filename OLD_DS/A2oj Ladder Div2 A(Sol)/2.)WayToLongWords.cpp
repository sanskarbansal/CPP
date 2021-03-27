#include<bits/stdc++.h>
using namespace std;

void longString(string input){
  int digits = input.size() - 2;
  string temp;
  while(digits != 0){
    char temp2 = (digits % 10) + '0';
    temp =temp2 + temp ;
    digits = digits / 10;
  }
  input = input[0] + temp + input[input.size() - 1];
  cout << input << endl;
}

int main() {
  int n, i = 1;
  cin >> n;
  string input;
  while(i <= n){
    cin >> input;
    if(input.size() - 1 < 10){
      cout << input << endl;
    }else{
      longString(input);
    }
    i++;
  }
  return 0;
}