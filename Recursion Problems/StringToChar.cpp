#include<iostream>
using namespace std;
int pow(int x, int y){
  if(y == 0){
    return 1;
  }
  int smallOutput =  pow(x, y - 1);
  return smallOutput * x;
}
int strlen(char input[]){
  int len = 0;
  for(int i = 0; input[i] != '\0'; i++)
    len++;
  return len;
}

int i = 0;

int stringToNumber(char input[]) {
  if(input[0] == '\0'){
    return 0;
  }
  int smallOutput = stringToNumber(input + 1);
  int temp = (input[0] - 48) ;
  return (temp * pow(10, i++))  + smallOutput;

}
int main(){
    char in[1000];
    cin >> in;
    int n = stringToNumber(in);
    cout << n;
}
