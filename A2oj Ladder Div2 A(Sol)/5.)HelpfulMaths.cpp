#include<iostream>
using namespace std;

int main(){
    string input;
    cin >> input;
    int arr[3] = {0};
    for(int i = 0; i < input.size(); i++){
        if(input[i] != '+'){
            arr[input[i] - 49]++;
        }
    }
    int n = arr[0]+arr[1]+arr[2];
    for(int i = 1; i <= n; i++){
        if(arr[0]> 0){
            cout << "1";
            arr[0]--;
        }else if(arr[1]>0){
            cout << "2";
            arr[1]--;
        }else{
            cout << "3";
            arr[2]--;
        }
        if(i != n){
            cout << "+";
        }
    }
    
}