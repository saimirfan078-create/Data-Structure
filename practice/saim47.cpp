#include<iostream>
using namespace std;
void insertionsort(int arr[],int size){
	for(int i = 1;i<size;i++){
		int key = arr[i];
		int j = i-1;
		if(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
	}
	arr[j+1]=key;
}
int main(){
    int arr[100];
    int size;

    cout<<"Enter size: ";
    cin>>size;

    for(int i=0; i<size; i++){
        cout<<"Enter value: ";
        cin>>arr[i];
    }

    insertionsort(arr,size);

    cout<<"Sorted array: ";

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
