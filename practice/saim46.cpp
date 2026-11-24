#include<iostream>
using namespace std;
void slectionsort(int arr[],int size){
	int minindex;
	for(int i = 0;i<size-1;i++){
		minindex=i;
		for(int j=i+1;j<size;j++){
			if(arr[j]<minindex){
				minindex=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[minindex];
		arr[minindex]=temp;
	}
}
int main(){
	int arr[100];
	int size;
	cout<<"enter size";
	cin>>size;
	for(int i = 0;i<size;i++){
		cout<<"enter values";
		cin>>arr[i];
	}
	slectionsort(arr,size);
	cout<<"sorted array";
	for(int i = 0;i<size;i++){
		cout<<arr[i];
	}
}
