#include<iostream>
#include<string>
using namespace std;

void helper(string input, int i ,string output){
	if(i >= input.size()){
        cout<<output<<endl;
        return ;
	}
	helper(input, i+1,output + input[i]);
	helper(input, i+1,output);
	return ;
}

void subsets(string input){
	return helper(input, 0, "");
}


int main(){
	string input;
	cin>>input;
	subsets(input);
	return 0;
}
