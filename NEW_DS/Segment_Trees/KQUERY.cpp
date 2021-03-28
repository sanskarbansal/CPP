/*
Link of the problem: https://www.spoj.com/problems/KQUERY/

Problem Statement: 
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.

Input Format: 
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 109).
Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.
In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 109).

Output Format: 
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.

Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 

Output
2
0
3 
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef long long ll;

vi v; 
vector<vector<int>> tree; 

void buildTree(int start, int end, int nodeAt=1){
    if(start == end){
        tree[nodeAt].pb(v[start]); 
        return; 
    }
    int mid = (start+end)/2; 
    buildTree(start, mid, 2*nodeAt); 
    buildTree(mid +1, end, 2*nodeAt + 1); 
    merge(all(tree[2*nodeAt]), all(tree[2*nodeAt +1]), back_inserter(tree[nodeAt])); 
}
int query(int start, int end, int ts, int te, int k, int nodeAt){
    if(ts > end || te < start ) return 0; 
    if(start <= ts && te <= end){
        return tree[nodeAt].end()-upper_bound(all(tree[nodeAt]), k);
    }
    int mid = (ts+te)/2; 
    return query(start, min(end, mid), ts, mid, k, 2*nodeAt) + query(max(start, mid+1), end, mid+1, te, k, 2*nodeAt+1) ;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q, i, j, k; 
    cin >> n; 
    for(i = 0; i < n; i++){
        int t; cin >> t; v.pb(t); 
    } 
    tree.resize(4*n); 
    buildTree(0, n-1); 
    
    cin >> q; 
    rep(l, q){
        cin >> i >> j >> k; 
        cout <<  query(i-1, j-1, 0, n-1,k,  1)   << endl; 
    }
}