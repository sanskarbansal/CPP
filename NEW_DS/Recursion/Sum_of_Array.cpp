/*
Problem Statement: 
Given an array of length N, you need to find and return the sum of all elements of the array.

Input Format: 
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format: 
Sum 

Constraints: 1 <= N <= 10^3

Sample Input1: 
3
9 8 9

Sample Output1: 
26

Sample Input2: 
3
4 2 1
Sample Output2:
7 
*/


#include<iostream>
using namespace std;

int sum(int input[], int n) {
  if(n == 1){
    return input[0];
  }
  int smallOutput = sum(input + 1, n - 1);
  return smallOutput + input[0];
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}



