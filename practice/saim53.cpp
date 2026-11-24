#include<iostream>
using namespace std;
struct node{
	char data;
	node*next;
};
class stack{
	private:
		node*head;
		public: 
		stack(){
			head=NULL;
		}
		void push(int x){
		node*newnode=new node;
		newnode->data=x;
		newnode->next=head;
		head=newnode;
}
		char pop(){
			if(head==NULL){
				cout<<"list is empaty";
			}
			else{
				node*temp=head;
				char T = temp->data;
				head=temp->next;
				delete temp;
				return T;
			}
		}
};
int main(){
	stack myStack;
	myStack.push('H');
myStack.push('e');
myStack.push('l');
myStack.push('l');
myStack.push('o');
cout<<myStack.pop();
}
