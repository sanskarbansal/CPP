#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; 
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		int temp ;
		cin >> temp;
		arr[temp-1] = i+1;
	}
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	delete [] arr;
}