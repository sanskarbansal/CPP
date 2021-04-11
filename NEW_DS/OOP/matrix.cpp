#include "Matrix.h"

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Matrix a, b; 
    cin >> a >> b; 
    Matrix result = a*b; 
    Matrix sum = a+b; 
    cout << result; 
    cout << endl; 
    cout << sum; 
    cout << "Dimensions: " << a.getDimension().first << " " << a.getDimension().second;  
}