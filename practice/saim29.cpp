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
newnode->next=head;
newnode->prev=NULL;
if(head!=NULL){
   head->prev=newnode;	
}
head=newnode;
	
}
void insertatend(int value){
	node*newnode=new node;
	newnode->data=value;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		newnode->prev=NULL;
	}
	node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}
void deleteatend(){
	node*temp=head;
	if(head==NULL){
		cout<<"invalid";
		
	}
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	node*delnode=temp->next;
	temp->next=NULL;
	delete delnode;
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
	insertatend(60);
	insertatend(80);
	deleteatend();
	display();	
}
