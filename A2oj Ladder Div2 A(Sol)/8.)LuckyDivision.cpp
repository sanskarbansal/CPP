#include<bits/stdc++.h>
using namespace std;

int arr[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};

int main(){
	int n;
	cin >> n;
	bool flag = 0;
	for(int i = 0; i < 14; i++){
		if(arr[i] > n){
			break;
		}
		if(n%arr[i]==0){
			flag = 1;
		}
	}
	if(flag){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}