// link to the problem first try then come to solution --> https://www.codechef.com/problems/GRAYSC


#include<iostream>
#include<vector>
using namespace std;
#define ll long long
int main(){
	unsigned ll n;
	cin>>n;
	vector<unsigned ll> input;
	for(ll i = 0;i<n; i++){
		unsigned ll t;
		cin>>t;
		if(n<130)
		    input.push_back(t);
	}
	if(n>=130){
		cout<<"Yes";
	    return 0;
	}
	for(int i=0; i<n;i++){
	    for(int j=i+1;j<n;j++){
		    for(int k=j+1;k<n;k++){
			    for(int l=k+1;l<n;l++){
				    if((input[i]^input[j]^input[k]^input[l])==0){
					    cout << "Yes";
					    return 0;
				    }
				}
		    }
	    }
	}
	cout << "No";
	return 0;
}
