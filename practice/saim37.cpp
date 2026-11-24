#include<iostream>
#include<cstring>
using namespace std;
class stack{
	private:
		int pos;
		int values[35];
		public:
			stack(){
				pos=-1;
			}
			void push(char x){
				if(pos==35){
					cout<<"overflow";
				}
				else{
					values[++pos]=x;
				}
			}
			char pop(){
				if(pos==-1){
					cout<<"array not exist";
				}
				else{
					return values[pos--];
				}
			}
};
int main(){
		stack mystack;
	string str="I LOVE PAKISTAN"; 
	for(int i = 0;i<str.length();i++){
	mystack.push(str[i]);
	}
	for(int i = 0;i<str.length();i++){
		cout<<mystack.pop();
	}
}
