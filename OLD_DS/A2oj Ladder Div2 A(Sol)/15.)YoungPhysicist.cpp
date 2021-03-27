#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,xSum = 0, ySum = 0, zSum = 0;
	cin >> n;
	while(n){
		int x, y, z;
		cin >> x >> y >> z;
		xSum+= x, ySum += y, zSum += z;
		n--;
	}
	if(xSum != 0 || ySum != 0 || zSum != 0){
		cout << "NO";
	}else{
		cout << "YES";
	}
}
