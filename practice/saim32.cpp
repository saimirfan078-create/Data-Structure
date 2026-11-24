#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
node*head=NULL;
node*last=NULL;
void insertatbeg(int value){
	node*newnode=new node;
	newnode->data=value;
	if(head==NULL){
		head=newnode;
		last=newnode;
		last->next=head;
	}
	else{
		newnode->next=head;
		head=newnode;
		last->next=head;
	}
}
void display(){
	node*temp=head;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=head);
}
int main(){
	insertatbeg(3);
	insertatbeg(4);
	insertatbeg(5);
	display();
}
