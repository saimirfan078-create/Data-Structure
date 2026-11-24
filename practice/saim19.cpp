#include<iostream>
using namespace std;
int main(){
	int arr[100];
	int size;
	cout<<"enter size";
	cin>>size;
	for(int i = 0;i<size;i++){
		cin>>arr[i];
	}
	if(size>0){
		for(int i = 0;i<size-1;i++){
			arr[i]=arr[i+1];
		}
		size--;
	}
	else{
	cout<<"list is empty";
}
for(int i = 0;i<size;i++){
	cout<<arr[i];
}
}
