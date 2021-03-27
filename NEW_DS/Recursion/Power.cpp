/*
Problem Statement: 
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
Input Format: 
Two integers x and n (separated by space)

Output Format: 
x^n (i.e. x raise to the power n)

Constrains: 
1 <= x <= 30
0 <= n <= 30

Sample Input: 
3 4 

Sample Output: 
81
*/


int power(int x, int n) {
  if(n == 0){
    return 1;
  }
  int smallOutput = power(x, n - 1);
  return x * smallOutput;
}

#include<bits/stdc++.h>
using namespace std;


int main(){
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
}


