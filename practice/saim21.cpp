#include<iostream>
using namespace std;
int main(){
	int arr[100];
	int size;
	int i = 0;
	bool found=false;
	int key;
	cout<<"enter size";
	cin>>size;
	for(int j = 0;j<size;j++){
		cin>>arr[j];
	}
	cout<<"enter element to find";
	cin>>key;
	while(i<size){
		if(arr[i]==key){
			found=true;
			break;
		}
		i++;
	}
	if(found==true){
		cout<<"element is found at "<<i;
		
	}
	else{
		cout<<"element is not found";
	}
}

