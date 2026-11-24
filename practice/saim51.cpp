#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
	node*prev;
};
node*head=NULL;
void insertatbeg(int value){
	node*newnode=new node;
	newnode->data=value;
	head->prev=newnode;
	newnode->next=head;
	newnode->prev=NULL;
	head=newnode;
}
void insertatanypoint(int pos,int value){
	node*newnode=new node;
	node*temp=head;
	newnode->data=value;
	newnode->next=NULL;
	for(int i=0;i<pos-1&&temp!=NULL;i++){
		temp=temp->next;
	}
	temp->next->prev=newnode;
	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next=newnode;
}
void insertatend(int value){
	node*newnode=new node;
	newnode->data=value;
	newnode->next=NULL;
	node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	newnode->prev=temp;
	temp->next=newnode;
}
void deleteatbeg(){
	node*temp=head;
	head=temp->next;
	head->prev=NULL;
	delete temp;
	
}
void deleteatanypoint(int pos){
	node*newnode=new node;
	node*temp=head;
	for(int i=0;i<pos-1&&temp!=NULL;i++){
		temp=temp->next;
	}
	node*del=temp->next;
	temp->next=del->next;
	temp->next->prev=temp;
	delete del;
}
void deleteatend(){
	node*temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
		
	}
	temp->next=NULL;
	delete temp;
}
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp=temp->next;
	}
}
int main(){
	insertatbeg(3);
	insertatbeg(4);
	insertatbeg(8);
	insertatbeg(9);
	insertatanypoint(2,5);
	insertatend(6);
	deleteatbeg();
	deleteatanypoint(3);
	deleteatend();
	display();
}
