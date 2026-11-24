#include<iostream>
using namespace std;
void merge(int arr[],int low,int high,int mid){
	int temp[100];
	int i = low;
	int j = mid+1;
	int k = low;
	while(i<=mid&&j<=high){
		if(arr[i]>arr[j]){
			temp[k]=arr[i];
			i++;
		}else{
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid){
		temp[k] = arr[i];
		k++;
		i++;
	}
	while(j<=high){
		temp[k] = arr[j];
		k++;
		j++	;
	}
	for(int i = low;i<=high;i++){
		arr[i]=temp[i];
			}
}
void mergesort(int arr[],int low,int high){
	int mid;
	if(low<high){
	mid = (low+high)/2;
	}
	mergesort(arr,low,mid);
	mergesort(arr,mid+1,high);
	merge(arr,low,high,mid);
}
int main(){
    int arr[100], size;

    cout << "Enter size: ";
    cin >> size;

    for(int i = 0; i < size; i++){
        cout << "Enter value: ";
        cin >> arr[i];
    }

    mergesort(arr, 0, size - 1);

    cout << "Sorted array: ";

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
