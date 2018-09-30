#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >>n ;
	int h[101] = {0};
	int g[101] = {0};
	for(int i = 0; i < n; i++){
		int h1, g1;
		cin >> h1 >> g1;
		h[h1]++; g[g1]++;
	}
	int ans = 0;
	for(int i = 0; i < 101; i++){
		if(h[i] != 0 && g[i]!= 0){
			ans += h[i]*g[i];
		}
	}
	cout << ans;
}
