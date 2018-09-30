#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, temp = 0;
    cin >> n;
    int input[n];
    for(int i = 0; i <  n; i++){
        cin >> input[i];
        temp += input[i];
    }
    sort(input, input + n);
    int ans = 0;
    int count = 0;
    for(int j = n-1; ans <= temp; j--){
        count++;
        ans += input[j];
        temp -= input[j];
    }
    cout << count;
    return 0;
}