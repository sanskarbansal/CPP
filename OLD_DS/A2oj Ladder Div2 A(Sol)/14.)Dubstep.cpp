#include<bits/stdc++.h>
using namespace std;

void dubStep(string input, bool flag = false){
	if(input.empty()){
		return;
	}
	if(input.size() < 3){
		cout << input;
		return;
	}
	if(input.substr(0, 3) == "WUB"){
		if(flag){
			cout << " ";
		}
		dubStep(input.substr(3), false);
	}else{
		cout << input[0];
		dubStep(input.substr(1),true);
	}
}

int main(){
	string input;
	cin >> input;
	dubStep(input);
}
