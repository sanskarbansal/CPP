#include<iostream>
using namespace std;

int checkL(string input1, string input2){
    int size = input1.size();
    for(int i = 0; i < size; i++){
        int n;
        if(input1[i] >= 97){
            n = input1[i] - 'a';
        }else{
            n = input1[i] - 'A';
        }
        int b;
        if(input2[i] >= 97){
            b = input2[i] - 'a';
        }else{
            b = input2[i] - 'A';
        }
        if(n > b){
            return 1;
        }else if(n < b){
            return -1;
        }
    }
    return 0;
}

int main(){
    string input1;
    string input2;
    cin >> input1;
    cin >> input2;
    cout << checkL(input1, input2);
}