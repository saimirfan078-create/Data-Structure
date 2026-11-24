#include<iostream>
using namespace std;
class stack{
	private:
		int tos;
		int values[10];
		
	public:
		stack(){
			tos=-1;
		}
		void push(char x){
			if(tos==9){
				cout<<"overflow";
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
	mystack.push('o');
	mystack.push('r');
	mystack.push('u');
	cout<<mystack.pop();
	cout<<mystack.pop();
	cout<<mystack.pop();
	cout<<mystack.pop();	
}
