#include<bits/stdc++.h>
using namespace std;
char mat[50][50];
int row, col;
void printMat(){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void floodFill(int i, int j, char ch, char toFill){
	if(i<0||j<0||i>=row||j>=col|| mat[i][j]!= ch){
		return;
	}
	mat[i][j] = toFill;
	floodFill(i+1, j, ch, toFill);
	floodFill(i, j+1, ch, toFill);
	floodFill(i-1, j, ch, toFill);
	floodFill(i, j-1, ch, toFill);
}

int main(){
    int x, y;
	cin >> row >> col >> x >> y;
	char toRep, toWith;
	cin >> toRep >> toRepWith;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> mat[i][j];
		}
	}
	cout << endl;
	floodFill(x,y,toRep,toRepWith);
	printMat();
}
