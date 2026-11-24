#include<iostream>;
using namespace std;
int main(){
	int arr[100];
	int size;
	int value;
	int key;
	int pos = -1;
	cout<<"Enter size";
	cin>>size;
	for(int i = 0;i<size;i++){
		cout<<"enter numbers";
		cin>>arr[i];
	}
	cout<<"enter value you want to insert";
	cin>>value;
	cout<<"enter value before which you want to insert";
	cin>>key;
	for(int i = 0;i<size;i++){
		if(arr[i]==key){
			pos = i;
			break;
		}
		
	}
	if(pos!=-1){
		for(int i = size;i>pos;i--){
			arr[i]=arr[i-1];
			
		}
	arr[pos]=value;
	size++;
}
else{
	cout<<"LIST NOT FOUND";
}
for(int i = 0;i<size;i++){
	cout<<arr[i];
}
}
