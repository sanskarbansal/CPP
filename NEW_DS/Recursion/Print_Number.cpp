/*
Problem Statement: 
Given is the code to print numbers from 1 to n in increasing order recursively. But it contains few bugs that you need to rectify such that all the test cases pass.

Input Format: 
Integer n
Output Format: 
Numbers from 1 to n (separated by space)
Constraints: 1 <= n <= 10000
Sample Input1: 
6

Sample Output1: 
1 2 3 4 5 6 

Sample Input2: 
4

Sample Output2: 
1 2 3 4 
*/
#include<iostream>
using namespace std;

void print(int n); 

int main(){
    int n;
    cin >> n;
  
    print(n);
}

void print(int n){
    if(n != 1){
      print(n - 1);     
    }
    cout << n << " ";
}
