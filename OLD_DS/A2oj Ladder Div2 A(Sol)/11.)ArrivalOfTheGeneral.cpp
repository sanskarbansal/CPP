#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, min = INT_MAX, max = INT_MIN;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] > max){
			max = arr[i];
		}
		if(arr[i]< min){
			min = arr[i];
		}
	}
	int countMax = 0, countMin= 0;
	bool x = true, y = true;
	for(int i = 0, j = n-1; i < n; i++, j--){
		if(arr[i]!= max && x == true){
			countMax++;
		}else{
			x = false;
		}
		if(arr[j]!= min&& y == true){
			countMin++;
		}else{
			y = false;
		}
		if(y == false && x == false)
			break;
	}
	if(countMin+countMax>=n)
		countMax--;
	cout <<  countMax + countMin;
	delete [] arr;
}
