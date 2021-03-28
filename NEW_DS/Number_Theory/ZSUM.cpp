/*
Link to problem: https://www.spoj.com/problems/ZSUM/
Problem Statement: 
For two given integers n and k find (Zn + Zn-1 - 2Zn-2) mod 10000007, where Zn = Sn + Pn and Sn = 1k + 2k + 3k + … + nk and Pn = 11 + 22 + 33 + … + nn.

Input Format: 
There are several test cases (≤ 10000). In each case two space separated positive integers n and k are given.
For last test case n and k are given as 0 0, which is not to be processed.

Constraints: 
1 < n < 200000000
0 < k < 1000000

Sample Input: 
10 3
9 31
83 17
5 2
0 0
Sample Output: 
4835897
2118762
2285275
3694
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
#define pb push_back
typedef long long ll;
#define mod 10000007
ll mult(ll a, ll b){
    ll result = 1; 
    while(b > 0){
        if(b &1) result = (result * a)%mod; 
        a = (a*a)%mod; 
        b = b >> 1; 
    }
    return result; 
}

ll result(ll n, ll k){
    return (2*(mult(n-1, k) + mult(n-1, n-1))%mod + (mult(n, k) + mult(n, n))%mod)%mod; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n, k; 
    cin >> n >> k; 
    while(n != 0 && k != 0){
        cout << result(n, k) << endl; 
        cin >> n >>k; 
    }
}
