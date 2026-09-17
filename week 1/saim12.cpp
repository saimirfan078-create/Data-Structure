#include<Iostream>
using namespace std;
int main(){
	string str;
	do{
		cout<<"Enter a text";
		getline(cin,str);
		cout<<"you Entered"<<str;
	}while(str!="goodbye");
}
