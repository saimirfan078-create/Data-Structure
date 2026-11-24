#include<iostream>
using namespace std;
int main(){
	int arr[100];
	int size;
	int key;
	int pos = -1;
	cout<<"enter size";
	cin>>size;
	for(int i = 0;i<size;i++){
		cin>>arr[i];
	}
	cout<<"enter position from where you want to delete";
	cin>>key;
	for(int i = 0;i<size;i++){
		if(arr[i]==key){
			pos = i;
			break;
		}
	}
	if(pos!=-1){
		for(int i = pos;i<size-1;i++){
			arr[i]=arr[i+1];
		}
		size--;
	}
	else{
		cout<<"list not found";
	}
	cout<<"Array list is:";
	for(int i = 0;i<size;i++){
		cout<<arr[i];
	}
	}

