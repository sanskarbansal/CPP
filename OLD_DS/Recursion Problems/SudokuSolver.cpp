#include<iostream>
using namespace std;
int sudoku[9][9];

bool isSafe(int i, int j , int no){
	for(int x=0;x<9;x++){
		if(sudoku[i][x]==no){
			return false;
		}
		if(sudoku[x][j]==no){
			return false;
		}
	}
	int sy = (i/3)*3, sx = (j/3)*3;
	for(int y=0;y<3;y++){
		for(int x=0;x<3;x++){
			if(sudoku[sy+y][sx+x]==no){
				return false;
			}
		}
	}
	return true;
}

bool sudokuSolver(int i=0,int j=0){
	if(j==9){
		return sudokuSolver(i+1, 0);
	}
	if(i==9){
		for(int y=0;y<9;y++){
			for(int x=0;x<9;x++){
				cout<<sudoku[y][x]<<" ";
			}
			cout << endl;
		}
		return true;
	}
	if(sudoku[i][j]!=0){
		return sudokuSolver(i,j+1);
	}
	for(int x=1;x<=9;x++){
		if(isSafe(i, j, x)){
			sudoku[i][j]=x;
			bool flag = sudokuSolver(i,j+1);
			if(flag){
				return true;
			}
			sudoku[i][j]=0;
		}
	}
	return false;
}


int main(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>sudoku[i][j];
		}
	}
	cout<<"-------------------------------\n\n\n";
	sudokuSolver();
}
/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0 
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9 
*/