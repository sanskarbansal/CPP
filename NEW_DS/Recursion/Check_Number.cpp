/*
Problem Statement: 
Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.

Input Format: 
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format: 
'true'/1 or 'false'/0
ˀˀ
Constraints: 
1 <= N <= 10^3

Sample Input1: 
3
9 8 10
8
Sample Output1: 
true or 1

Sample Input2: 
3
9 8 10
2

Sample Output2: 
false or 0
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
#define pb push_back
typedef long long ll;

bool checkNumber(int input[], int size, int x) {
  if(size == 0){
    return false;
  }
  if(input[0] == x){
    return true;
  }
  bool smallOutput = checkNumber(input + 1, size - 1, x);
  
  return smallOutput;
  
}


int main(){

    int n, t; 
    cin >> n; 
    int arr[1001]; 
    for(int i = 0;i < n; i++) cin >> arr[i]; 
    cin >> t; 
    cout << checkNumber(arr, n, t); 
}