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
			void push(int x){
				if(tos>=9){
					cout<<"Overflow";
				}
				else{
					values[++tos]=x;
				}
			}
			char pop(){
				if(tos==-1){
					cout<<"onderflow";
					return ' ';
					
				}
				else{
					return values[tos--];
				}
			}
};
int main(){
	stack myStack;
	myStack.push('B');
    myStack.push('S');
    myStack.push('S');
    myStack.push('E');
    myStack.push('3');
    myStack.push('Z');

    cout << myStack.pop();
    cout << myStack.pop();
    cout << myStack.pop();
    cout << myStack.pop();
    cout << myStack.pop();
    cout << myStack.pop();


    return 0;

}
