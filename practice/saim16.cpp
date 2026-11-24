#include<iostream>
using namespace std;
int main(){
	int arr[100];
	int size;int value;
	cout<<"Enter size";
	cin>>size;
	for(int i = 0;i<size;i++){
		cout<<"enter values";
		cin>>arr[i];
	}
	cout<<"value insert at start";
	cin>>value;
for(int i = size;i>0;i--){
	arr[i]=arr[i-1];
}
arr[0]=value;
size++;
	for(int i = 0;i<size;i++){
		cout<<arr[i]<<'\n';
	}
}
