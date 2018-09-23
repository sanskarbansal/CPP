//This Program Print the Subsets of The Given Integer Array

#include<iostream>
using namespace std;

void helper(int input[], int start, int n, int output[],int m ){
  if( n <= 0){
    for(int i = m - 1; i >= 0; i--){
      cout << output[i] << " ";
    }
    cout << endl;
    return;
  }
  helper(input,start + 1,n - 1,output, m);

  int newOutput[100];
  for(int i = m; i > 0; i--){
    newOutput[i] = output[i-1];
  }

  newOutput[0] = input[start];
  helper(input,start + 1,n - 1,newOutput,m +1);
}

void printSubsetsOfArray(int input[], int size) {
  int output[1000] = {0};
  helper(input,0,size,output,0);
  return;
}

int main(){
    int n;
    cin >> n;
    int* input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    printSubsetsOfArray(input, n);
}


