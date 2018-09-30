#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
  //Dynamically we will make an array of size Ending Index - Starting Index + 1;
  int*temp = new int[e - s + 1];
  int mid = (s+e)/2;
  int i = s, j = mid + 1, k = 0;
  //We will take two variable pointing on the starting index and mid + 1 index than compare all the elements and fill the elements in increasing order in the temp array;
  while(i <= mid && j <= e){
    temp[k++]  = (arr[i]<=arr[j])?arr[i++]:arr[j++];
  }
  //If some elements are left than we will exactly copy them in temp array;
  while(i <= mid){
    temp[k++] = arr[i++];
  }
  while(j <=e){
    temp[k++] = arr[j++];
  }
  k = 0;
  //Than finally we will copy all the elements from temp array to the orignal array and delete the dynamically allocated array ;
  for(int i = s; i <= e; i++){
    arr[i] = temp[k++];
  }
  delete [] temp;
}

void sort(int *arr, int s, int e){
  if(s >=e){
    return;
  }
  int mid = (s+e)/2;
//Recursion will sort the array from starting index i.e s to the mid index and from (mid + 1) index to ending index i.e e;
  sort(arr, s , mid);
  sort(arr, mid + 1 , e);
//merge function will merge the both halves of the array in sorting order, so that full array becomes sorted;
  merge(arr,s, e);
}

void mergeSort(int * arr, int n){
  //This is the function which will be used by the user;
  sort(arr, 0, n-1);
};

int main(){
  int n;
  cin >> n;
  int *input = new int[n];
  for(int i = 0; i < n; i++){
    cin >> input[i];
  }
  mergeSort(input, n);
  for(int i = 0; i < n; i++){
    cout << input[i] << " ";
  }
  delete [] input;
}
