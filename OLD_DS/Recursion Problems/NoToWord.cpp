#include<iostream>
using namespace std;

string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void ntow(int n){
	if(n==0){
		return;
	}
	ntow(n/10);
	cout << arr[n%10] << " ";
}

int main(){
	int n;
	cin >> n;
	ntow(n);
}
