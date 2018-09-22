#include<iostream>
using namespace std;

int cricket(int n, int *arr){
  if(n == 0){
    return 0;
  }
  int t = cricket(n -1, arr + 1);
  int x = arr[0];
  int ans = 0;
  for(int i = 1; i < n; i++){
    ans += abs(x - arr[i]);
  }
  return ans + t;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    cout << cricket(n, arr);
    delete[] arr;
}
