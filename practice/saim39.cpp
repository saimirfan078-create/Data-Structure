#include<iostream>
#include<stack>
using namespace std;
bool isbalance(string expr){
	stack<char> s;
	char ch;
	for(int i = 0;i<expr.length();i++){
		if(expr[i]=='('||expr[i]=='['||expr[i]=='{'){
			s.push(expr[i]);
		}
		else if(expr[i]==')'||expr[i]==']'||expr[i]=='}'){
			if(s.empty()){
			
			return false;}
		ch=s.top();
		s.pop();	
		switch(expr[i]){
			case'}':
				if(ch=='('||ch=='[')
				return false;
				break;
			case')':
				if(ch=='{'||ch=='[')
				return false;
				break;
			case']':
				if(ch=='{'||ch=='(')
				return false;
				break;
		}	
		}
	}
	return s.empty();
}
int main(){
	string str="[{}(){()}]";
	if(isbalance(str)){
		cout<<"expression is balance";
	}
	else{
		cout<<"not balance";
	}
}
