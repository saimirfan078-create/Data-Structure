#include<iostream>
using namespace std;
int main(){
 int arr[10]={10,20,30};
 int size = 3;
 int value = 60;
 arr[size]= value;
 size++;
 for(int i = 0 ; i<4;i++){
 	cout<<arr[i]<<'\n';
 }
}
