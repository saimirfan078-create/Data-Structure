#include<iostream>
using namespace std;
int main(){
int arr[100];
int size;
int key;
int value;
int pos = -1;
cout<<"Enter size";
cin>>size;
for(int i = 0;i<size;i++){
	cout<<"Enter numbers";
	cin>>arr[i];
}
cout<<"Enter value that is we inserts";
cin>>value;
cout<<"enter the position after which we want";
cin>>key;
for(int i = 0;i<size;i++){
	if(arr[i]==key){
		pos = i;
		break;
	}
}
	if(pos!=-1){
		for(int i = size;i>pos+1;i--){
			arr[i]=arr[i-1];
		}
		arr[pos+1]=value;
		size++;
	}
	else{
		cout<<"value not found";
	}
cout<<"ARRAY List is";
for(int i = 0;i<size;i++){
	cout<<arr[i];
}

}


