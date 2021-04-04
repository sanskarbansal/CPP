/* 
Problem Statement: 
For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].

Explanation: 
On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

Similarly, we can deduce the remaining results.

Input Format: 
The first line of input contains an integer N, denoting the total number of days.

The second line of input contains the stock prices of each day. A single space will separate them.

Output Format: 
The only line of output will print the span for each day's stock price. A single space will separate them.

Constraints: 
0 <= N <= 10^7
1 <= X <= 10^9
Where X denotes the stock's price for a day.

Time Limit: 1 second

Sample INput: 
8
60 70 80 100 90 75 80 120
Sample Output: 
1 2 3 4 1 1 2 8 

*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> arr; 
vector<int> spans; 

void solveProblem(int n){
    spans[0] = 1; 
    stack<int> s; 
    s.push(0); 
    for(int i = 1; i < n; i++){
        while(!s.empty() && arr[i] > arr[s.top()]){
            s.pop(); 
        }
        if(s.empty()){
            spans[i] = i+1; 
        }else{
            spans[i] = i - s.top(); 
        }
        s.push(i); 
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; 
    cin >> n; 
    spans.resize(n); 
    arr.resize(n); 
    for(int i = 0; i < n; i++) cin >> arr[i]; 
    solveProblem(n); 
    for(auto &x: spans) cout << x << " "; 
}