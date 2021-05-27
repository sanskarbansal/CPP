#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()


typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;


vector<vector<float>*> skipRowCol(vector<vector<float>*> mat, int ySkip, int xSkip){
    vector<vector<float>*> output; 
    rep(i, mat.size()){
        if(i == ySkip) continue; 
        output.push_back(new vector<float>()); 
        rep(j, mat.size()){
            if(j == xSkip) continue; 
            output[output.size()-1]->push_back(mat[i]->at(j)); 
        }
    }
    return output; 
}

float det(vector<vector<float>*> mat){
    int n = mat.size(); 
    if(n == 2){
        return mat[0]->at(0)*mat[1] -> at(1) - mat[0] -> at(1)*mat[1] -> at(0); 
    }
    int sign = 1; 
    float ans = 0; 
    rep(i, n){
        vector<vector<float>*> matAfterSkip = skipRowCol(mat, 0, i); 
        ans = ans + sign*(mat[0] -> at(i))*det(matAfterSkip); 
        rep(i, matAfterSkip.size()) delete matAfterSkip[i]; 
        sign = 0 - sign; 
    }
    return ans; 
}

vector<float> findSolution(vector<vector<float>*> A, vector<float> *result){
    vector<float> solutions(result->size()); 
    float detA = det(A); 
    int n = result -> size(); 
    rep(i, n){
        vector<float> *t = A[i]; 
        A[i] = result; 
        float idet = det(A); 
        solutions[i] = idet/detA; 
        A[i] = t; 
    }
    return solutions; 
}


vector<vector<float>*> transpose(vector<vector<float>*> mat){
    int n = mat.size(); 
    vector<vector<float>*> trans(n); 
    rep(i, n){
        trans[i] = new vector<float>(n); 
    }
    rep(i, n){
        rep(j, n){
            trans[i]->at(j) = mat[j]->at(i); 
        }
    }
    return trans; 
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; 
    vector<vector<float>*> mat(n); 
    rep(i, n){
        mat[i] = new vector<float>(); 
        rep(j, n){
            float x; cin >> x; 
            mat[i] -> push_back(x); 
        }
    }

    mat = transpose(mat); 
    vector<float>* result = new vector<float>(); 
    rep(i, n){
        float x; cin >> x; 
        result -> push_back(x) ; 
    }
    vector<float> solutions = findSolution(mat, result) ; 
    rep(i, n) cout << solutions[i] << endl; 
    
    delete result; 
    rep(i, n) delete mat[i]; 
}