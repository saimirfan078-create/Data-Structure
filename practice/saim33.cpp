#include<iostream>
using namespace std;
class stack{
private:
int tos;
char values[10];
public:
stack(){
tos=-1;
}	
void push(char x){
	if(tos==9){
		cout<<"OVERFLOW";
	}
	else{
	values[++tos]=x;
}
}
char pop(){
	if(tos==-1){
		cout<<"underflow";
		
	}
	else{
		return values[tos--];
	}
}

};
int main(){
	stack mystack;
	mystack.push('s');
	mystack.push('h');
	mystack.push('f');
	mystack.push('a');
	
	cout<<mystack.pop();
	cout<<mystack.pop();
	cout<<mystack.pop();
	cout<<mystack.pop();
}
