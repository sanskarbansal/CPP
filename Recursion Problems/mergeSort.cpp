#include<iostream.h>
using namespace std 

void merge(int *arr, int si, int ei){
	int midIndex = (si+ei)/2;
	int i = si, j = mid+1, int k = 0;
	int *temp = new int[ei-ei+1];
	while(i <= mid && j <= ei){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i];
		}else{
			temp[k++] = arr[j];
		}
	}
	while(i <= mid){
		temp[k++] = arr[i];
	}
	while(j <=ei){
		temp[k++] = arr[j];
	}
	i = si;
	k = 0;
	while(i <= ei)
		arr[i++] =  temp[k++]
	return;
}

void sortHelper(int *arr, int si, int ei){
	if(si >=ei){
		return;
	}
	int mid = (si+ei)/2;
	sortHelper(arr,si, mid);
	sortHelper(arr, mid+1, ei);
	merge(arr, si, ei);
}
void sort(int *arr, int n){
	sortHelper(arr, 0, n-1);
}
int main(){

}