#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key){
	int low = 0;
	int high = size-1;
	int mid;
	while(low<=high){
	mid=(low+high)/2;
	if(arr[mid]==key){
		return mid;
	}
	else if(mid<key){
		low=mid+1;
	}
	else{
		high=mid-1;
	}
	}
	return -1;
}
int main(){
	int arr[100];
	int size;
	int key;
	cout<<"enter size";
	cin>>size;
	for(int i = 0;i<size;i++){
		cout<<"enter values";
		cin>>arr[i];
	}
	cout<<"enter value to searct";
	cin>>key;
	cout<<"location is index : " << binarysearch(arr,size,key);
}
