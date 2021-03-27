/*
Problem Statement: 
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.

Input Format: 
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format: 
indexes where x is present in the array (separated by space)

Constraints: 
1 <= N <= 10^3

Sample Input1: 
5
9 8 10 8 8
8
Sample Output1: 
1 3 4

*/

#include<bits/stdc++.h>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
  if(size == 0){
    return 0;
  }
  int smallOutput = allIndexes(input + 1, size - 1, x, output);
  if(input[0] == x){
    if(smallOutput > 0){
      for(int i = smallOutput - 1; i >= 0; i--){
        ++output[i];
        int temp = output[i];
        output[i] = output[i - 1];
        output[i + 1] = temp;
        if(i == 0){output[0] = 0;}
      }
      return smallOutput + 1;
    }else{
      output[0] = 0;
      return smallOutput + 1;
    }
  }
  for(int i = 0; i < smallOutput; i++){
    output[i]++;
  }

  return smallOutput;
}



int main(){
    int n, t;  
    cin >> n; 
    int arr[1001];
    for(int i = 0; i < n; i++) cin >> arr[i]; 
    cin >> t;  
    int result[1001]; 
    int r = allIndexes(arr, n, t, result); 
    for(int i = 0; i < r; i++) cout << result[i] << " "; 
    return 0; 
}
