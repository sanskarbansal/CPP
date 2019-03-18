#include<bits/stdc++.h>
using namespace std;


int determinant(vector<vector<int> > &v, int n){
	if(n == 2){
		return v[0][0]*v[1][1] - v[1][0]*v[0][1];
	}
	int ans = 0, sign = 1;
	for(int x = 0; x < n; x++){
		int si = 0;
		vector<vector<int> > sbm(n-1, vector<int>(n-1));
		for(int i = 1; i < n; i++){
			int sj = 0;
			for(int j = 0; j < n; j++){
				if(x == j) continue;
				sbm[si][sj] = v[i][j];
				sj++;
			}
			si++;
		}
		ans += sign*(v[0][x]*determinant(sbm, n-1));
		sign = -sign;
	}
	return ans;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cout << "Enter the order of the matrix: ";
	int n; cin >> n;
	vector<vector<int> > v(n, vector<int>(n));
	for(int i= 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> v[i][j];
	}
	cout << "\nDeterminant of this matrix is : " << determinant(v, n);
}
