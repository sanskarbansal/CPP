#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()


typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;


vector<vi> skipRowCol(vector<vi> &mat, int ySkip, int xSkip){
    vector<vi> output; 
    rep(i, mat.size()){
        if(i == ySkip) continue; 
        output.push_back(vi()); 
        rep(j, mat.size()){
            if(j == xSkip) continue; 
            output[output.size()-1].push_back(mat[i][j]); 
        }
    }
    return output; 
}

int det(vector<vi> mat){
    int n = mat.size(); 
    if(n == 2){
        return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0]; 
    }
    int sign = 1; 
    int ans = 0; 
    rep(i, n){
        ans = ans + sign*mat[0][i]*det(skipRowCol(mat, 0, i)); 
        sign = 0 - sign; 
    }
    return ans; 
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; 
    vector<vi> mat(n, vi(n)); 
    rep(i, n){
        rep(j, n) cin >> mat[i][j]; 
    }
    
    cout << det(mat); 
}