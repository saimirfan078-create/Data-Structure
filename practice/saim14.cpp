#include<iostream>
using namespace std;
int main(){
	int arr[10]={10,20,30};
	int size = 3;
	int value = 40;
	for(int i = size;i>0;i--){
		arr[i]=arr[i-1];
	}
	arr[0]=value;
	for(int i = 0;i<=size;i++){
		cout<<arr[i];
	}
}
