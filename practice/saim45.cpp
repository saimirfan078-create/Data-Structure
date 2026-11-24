#include<iostream>
using namespace std;
void bubblesort(int arr[],int size){
	int temp;
	for(int i=0;i<size-1;i++){
		for(int j = 0;j<size-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main(){
	int arr[100];
	int size;
	cout<<"Enter size";
	cin>>size;
	for(int i =0;i<size;i++){
		cout<<"Enter values";
		cin>>arr[i];
	}
	bubblesort(arr,size);
	cout<<"sorted array is : " ;
	for(int i = 0; i<size;i++){
		cout << arr[i];
	}
}
