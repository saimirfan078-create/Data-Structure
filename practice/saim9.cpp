#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
	node*prev;
};
node*head=NULL;
void insertatbeg(int value){
	node*newnode = new node;
	newnode->data=value;
	newnode->next=head;
	newnode->prev=NULL;
	if(head!=NULL){
		head->prev=newnode;
	}
	head=newnode;
}
void deleteatbeg(){
	if(head == NULL){
		cout<<"list is empaty";
	}
	node*temp = head;
	head=head->next;
	if(head!=NULL){
		head->prev=NULL;
	}
	delete temp;
}
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
int main(){
	insertatbeg(10);
	insertatbeg(20);
	insertatbeg(30);
	deleteatbeg();
	display();	
}
