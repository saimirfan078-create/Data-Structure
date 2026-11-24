#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
class stacklinked{
	private:
	node*head;
	public:
		stacklinked(){
	head=NULL;
}
	void push(char x){
		node*newnode=new node;
		newnode->data=x;
		newnode->next=head;
		head=newnode;
	}
	char pop(){
		
		if(head==NULL){
			cout<<"no list is found";
		}
		else{
			node*temp=head;
			char T=temp->data;
			head=temp->next;
			delete temp;
		return T;}
	}
};
int main(){
	stacklinked sl;
	sl.push('s');
	sl.push('b');
	sl.push('l');
	sl.push('q');
	sl.push('c');
	cout<<sl.pop();
	cout<<sl.pop();
	cout<<sl.pop();
	cout<<sl.pop();
	cout<<sl.pop();
}
