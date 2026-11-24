#include<iostream>
using namespace std;
class stack{
	private:
		int pos;
		char values[35];
		public:
			stack(){
				pos=-1;
			}
			void push(string x){

					for(int i=0;i<x.length();i++){
				if(pos==35){
					cout<<"overflow";
				}		
					else{
						values[++pos]=x[i];
					}
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
	string s="I LOVE PAKISTAN";
	mystack.push(s);
	for(int i = 0;i<s.length();i++){
	cout<<mystack.pop();
}
	}

