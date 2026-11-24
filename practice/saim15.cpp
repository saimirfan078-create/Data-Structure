#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> arr;
	int value;
	char choice;
	do{
		cout<<"Enter Number";
		cin>>value;
		arr.push_back(value);
		cout<<"Do you want to enter more Y/N";
		cin >> choice;
	}while(choice=='y'||choice=='Y');
	cout<<"Your arraylist is";
	for(int i = 0;i<arr.size();i++){
	cout<<arr[i]<<'\n';
	}
}
