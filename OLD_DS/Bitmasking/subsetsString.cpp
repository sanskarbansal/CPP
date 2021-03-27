#include<bits/stdc++.h>
using namespace std;

void helper(char *input, int n){
  //Prints input[ith] if the ith bit of the number is 1.
  int i = 0;
  while(n){
    if(n&1){
      cout << input[i];
    }
    i++;
    n = n >> 1;
  }
  cout << "\n";
}

void subsets(char *input){
  int size =  strlen(input);
  int ways = (1 << size);
  for(int i = 0; i < ways; i++){
    helper(input, i);
  }
}

int main(){
  char a[100];
  cin >> a;
  subsets(a);
  return 0;
}
