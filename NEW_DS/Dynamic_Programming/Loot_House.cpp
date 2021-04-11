//Link: https://www.codingninjas.com/codestudio/problems/loot-houses_630510
#include<bits/stdc++.h>
using namespace std; 

int maxMoneyLooted(vector<int> &arr, int n)
{
    
    vector<int> dp(n, 0); 
    if(n >= 2){
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);         
    }else if(n==1){
        return arr[0]; 
    }else{
        return 0; 
    }
    for(int i = 2; i < n; i++){
        if(dp[i-1] > arr[i] + dp[i-2]){
            dp[i] = dp[i-1]; 
        }else{
            dp[i] = dp[i-2] + arr[i]; 
        }
    }
    return dp[n-1]; 
}
int main(){
    int n; 
    cin >> n; 
    vector<int> arr(n); 
    for(int i = 0; i < n; i++) cin >> arr[i]; 
    cout << maxMoneyLooted(arr, n); 
}

