#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool compare(pair<int,int> p1, pair<int,int> p2){
	return p1.second > p2.second;
}

int main(){
	int n;
	cin >> n;
	pair<int,int> input[500000];
	for(int i = 0; i < n; i++){
		int a , b, c;
		cin >> a >> b >> c;
		input[i].first = a;
		input[i].second = b+c;
	}
	sort(input, input + n, compare);
	int max = INT_MIN;
	vector<ll> temp;
	temp.push_back(input[0].first);
	for(int i = 1; i < n; i++){
		temp.push_back(input[i].first + temp[i-1]);
	}

	for(int i = 0; i < n; i++){
		int t = temp[i] + input[i].second;
		if(t > max){
			max = t;
		}
	}
	cout << max;
}
