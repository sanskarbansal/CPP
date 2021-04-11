#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
#define pb push_back
typedef long long ll;
vi arr; 
vi subsets; 
void subset(int k){
    if(k == arr.size()){
        for(auto x: subsets) cout << x << " "; 
        cout << endl; 
        return; 
    }
    subsets.pb(arr[k]); 
    subset(k+1); 
    subsets.pop_back(); 
    subset(k+1); 
    return; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); 
    int n; 
    cin >> n; 
    arr.resize(n); 
    rep(i, n) cin >> arr[i]; 
    subset(0); 
}