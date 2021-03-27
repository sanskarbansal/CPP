#include<iostream>
using namespace std;

int n;
int **board;

bool iSafe(int x, int y){
	for(int i=0;i<n;i++){
		if(board[y][i] == 1){
			return false;
		}
	}
	for(int i=0;i<n;i++){
		if(board[i][x] == 1){
			return false;
		}
	}
	int i=x-1;
	int j=y-1;
	while( i>=0 && j>=0){
		if(board[j][i] == 1)
			return false;
		i--;
		j--;
	}
	i=x+1;
	j=y+1;
	while( i<n && j<n){
		if(board[j][i] == 1)
			return false;
		i++;
		j++;
	}
	i=x-1;
	j=y+1;
	while( i>=0 && j<n){
		if(board[j][i] == 1)
			return false;
		i--;
		j++;
	}
	i=x+1;
	j=y-1;
	while( i<n && j>=0){
		if(board[j][i] == 1)
			return false;
		i++;
		j--;
	}
	return true;
}

bool configuration(int j){
	if(j==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]==1)
					cout<<"q";
				else
					cout<<"-";
			}
			cout<<endl;
		}
		cout <<"\n\n";
		return false;
	}
	for(int i=0;i<n;i++){
		if(iSafe(i, j)){
			board[j][i]=1;
			bool flag=configuration(j+1);
			if(flag){
				return true;
			}
			board[j][i]=0;
		}
	}
	return false;
}


int main(){
	cin>>n;
	board=new int*[n];
	for(int i=0;i<n;i++){
		board[i]=new int[n];
		for(int j=0;j<n;j++)
			board[i][j]=0;
	}
	bool flag = configuration(0);
    return 0;
}
