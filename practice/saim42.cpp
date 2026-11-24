#include<iostream>
using namespace std;
int linearsearch(int arr[],int key,int size){
	for(int i = 0;i<size;i++){
		if(arr[i]==key){
		return i;
	}
}return -1;
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
	cout<<"location is index : " << linearsearch(arr,key,size);
}
