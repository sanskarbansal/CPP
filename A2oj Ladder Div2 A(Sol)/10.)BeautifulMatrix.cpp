#include<bits/stdc++.h>
using namespace std;

int main(){
	int mat[5][5];
	int r, c;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 1){
				r = i;
				c = j;
			}
		}
	}
	cout << abs(2 - r)+abs(2-c);
}