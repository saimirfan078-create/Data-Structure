#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*head=NULL;
void insertatbeg(int value){
	Node*newnode=new Node;
	newnode->data=value;
	newnode->next=head;
	head = newnode;
}
void insertatend(int value){
	Node*newnode=new Node;
	newnode->data=value;
	newnode->next=NULL;
	if(head==NULL){
		head = newnode;
		return;
	}
	Node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
}
void deleteatend(){
	Node*temp=head;
	while(temp->next->next!=NULL){
		temp = temp->next;
	}
	delete temp->next;
	temp->next=NULL;
}
void display(){
	Node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp=temp->next;
	}}
	int main(){
		insertatbeg(10);
		insertatbeg(20);
		insertatbeg(30);
	insertatend(50);
	deleteatend();
		display();
		
	
}
