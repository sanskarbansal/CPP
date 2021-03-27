#include<bits/stdc++.h>
using namespace std;

//Link to the problem. Try,Repeate and than see the solution(Easy Problem)-->https://codeforces.com/problemset/problem/405/A 


int main(){
    int n;
    cin >> n;
    vector<long long> input;
    for(int i = 0; i < n; i++){
        long long t;
        cin >> t;
        input.push_back(t);
    }
    sort(input.begin(), input.end());
    for(int i = 0; i < n; i++){
        cout << input[i] << " ";
    }
    return 0;
}
