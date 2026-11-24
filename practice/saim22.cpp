#include<iostream>
using namespace std;
int main(){
	int arr[100];
	int size;
	int key;
	int high=size-1;
	int mid;
	int low = 0;
	bool found = false;
	cout<<"Enter size";
	cin>>size;
	for(int i = 0;i<size;i++){
		cin>>arr[i];
	}
	cout<<"enter element to search";
	cin>>key;
	while(low<=high){
		mid = low+high/2;
		if(arr[mid]=key){
			found = true;
			break;
		}
		else if(arr[mid]<key){
			low=mid+1;
		}
		else{
			low=mid-1;
		}
	}
	if(found==true){
		cout<<"Element is found"<<mid;
	}
	else{
		cout<<"element not found";
	}
}
