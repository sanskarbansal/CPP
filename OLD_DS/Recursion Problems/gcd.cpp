#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
    if(x == 0){
        return y;
    }else if(y == 0){
        return x;
    }
    return gcd(y, x%y);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}
