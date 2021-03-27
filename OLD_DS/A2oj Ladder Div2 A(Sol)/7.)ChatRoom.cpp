#include<iostream>
using namespace std;

bool check(string input){
    string temp = "hello";
    for(int i = 0; i < input.size(); i++){
        if(temp[0] == input[i]){
            temp = temp.substr(1);
        }
    }
    return temp.empty();
}

int main(){
    string input;
    cin >> input;
    if(check(input)){
        cout << "YES";
    }else{
        cout << "NO";
    }
}