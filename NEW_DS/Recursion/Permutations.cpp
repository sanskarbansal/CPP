#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
#define pb push_back
typedef long long ll;
vi arr; 
vi p; 
void permutations(int j){
    int n = arr.size(); 
    if(j == n){
        for(auto x: p) cout << x << " "; 
        cout << "\n"; 
        return; 
    }
    for(int i = j; i < n; i++){
        int t = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = t; 
        p.pb(t); 
        permutations(j+1); 
        p.pop_back(); 

    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; 
    cin >> n; 
    arr.resize(n); 
    rep(i, n) cin >> arr[i]; 
    permutations(0); 
}