/*
Problem Statement: 
Given the code to find out and return the number of digits present in a number recursively. But it contains few bugs, that you need to rectify such that all the test cases should pass.

Input Format: 
Integer n

Output Format: 
Count of digits

Constraints: 1 <= n <= 10^6

Sample Input1: 
156

Sample Output1: 
2

Sample Input2: 
7

Sample Output2: 
1
*/

#include<iostream>

using namespace std;

int count(int n){
    if(n == 0){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}



int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


