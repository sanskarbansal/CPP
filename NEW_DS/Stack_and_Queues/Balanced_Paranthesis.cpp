/*
Problem Statement: 
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
Example: 
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.

Input Format: The first and the only line of input contains a string expression without any spaces in between.
Output Format: The only line of output prints 'true' or 'false'.

Constraints: 
1 <= N <= 10^7
 Where N is the length of the expression.

Time Limit: 1sec

Sample Input: 
(()()())
Sample Output: 
true; 
Sample Input: 
()()(()
Sample Output: 
false

*/

#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string input){
    stack<char> s; 
    int n = input.length(); 
    for(int i = 0; i < n; i++){
        if(input[i]=='('||input[i]=='{' || input[i]=='['){
            s.push(input[i]); 
        }else{
            if(s.empty()) return false; 
            char t = s.top(); 
            if(t == '(' && input[i] != ')' )return false; 
            else if(t == '{' && input[i]!= '}') return false; 
            else if(t == '[' && input[i] != ']') return false; 
            s.pop(); 
        }
    }
    return s.empty(); 
}

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}

