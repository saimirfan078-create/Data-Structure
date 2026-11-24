#include<iostream>
using namespace std;
void insertatbeg(int arr[],int value,int &size){
	for(int i = size;i>0;i--){
		arr[i]=arr[i-1];
		
	}
	arr[0]=value;
	size++;
}
void deleteatstart(int arr[],int &size){
	for(int i = 0;i<size-1;i++){
		arr[i]=arr[i+1];
	}
	size--;
}
void insertatanypoint(int arr[],int pos,int value,int &size){
	for(int i = size;i>pos;i--){
		arr[i]=arr[i-1];
	}
	arr[pos]=value;
	size++;
}
void deleteatanypoint(int arr[],int &size,int pos){
	for(int i =pos;i<size-1;i++){
		arr[i]=arr[i+1];
	}
	size--;
}
void insertatend(int arr[],int value,int &size){
	arr[size]=value;
	size++;
}
void deleteatend(int &size){
	size--;
}
int main(){
	int arr[100];
	int size;
	int value;
	int pos;
	int ab;
	int del;
	cout<<"Enter size";
	cin>>size;
	for(int i = 0;i<size;i++){
		cout<<"enter value";
		cin>>arr[i];
	}
	cout<<"enter value you want to enter";
	cin>>value;
	insertatbeg(arr,value,size);
	for(int i=0;i<size;i++){
		cout<<arr[i];}
		deleteatstart(arr,size);
		cout<<"after deletion";
		for(int i=0;i<size;i++){
		cout<<arr[i];}
		cout<<"enter a index where you want to insert";
		cin>>pos;
		cout<<"enter a value you want to insert";
		cin>>ab;
		insertatanypoint(arr,pos,ab,size);
		cout<<"after insertion";
		for(int i=0;i<size;i++){
		cout<<arr[i];}
		cout<<"enter a index where you want to delete";
		cin>>del;
		deleteatanypoint(arr,size,del);
		cout<<"after any point deletion";
		for(int i=0;i<size;i++){
		cout<<arr[i];}
		cout<<"enter value enter at last";
		int las;
		cin>>las;
		insertatend(arr,las,size);
		cout<<"after insertion at last";
		for(int i=0;i<size;i++){
		cout<<arr[i];}
		deleteatend(size);
		cout<<"after deletion";
		for(int i=0;i<size;i++){
		cout<<arr[i];}
	
	}
