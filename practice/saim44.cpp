#include<iostream>
using namespace std;
int slidingwindow(int arr[],int size,int k){
	int sum = 0;
	int maxsum;
	for(int i=0;i<k;i++){
		sum = sum + arr[i];
	}
	maxsum=sum;
	for(int i=k;i<size;i++){
		sum = sum - arr[i-k];
		sum = sum + arr[i];
		if(sum>maxsum){
			maxsum=sum;
		}
	}
	return maxsum;
}
int main(){
int arr[100];
int size;
int k;
cout<<"enter size";
cin>>size;
for(int i=0;i<size;i++){
	cout<<"enter values";
	cin>>arr[i];
}
cout<<"enter window size";
cin>>k;
cout<<"maxsum"<<slidingwindow(arr,size,k);
}
