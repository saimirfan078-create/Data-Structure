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
void insertatanypoint(int value,int position){
	node*newnode=new node;
	newnode->data=value;
	if(position==1){
		insertatbeg(value);
		return;
	}
	node*temp=head;
	for(int i = 1;i<position-1&&temp!=NULL;i++){
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	if(temp->next!=NULL){
		temp->next->prev=newnode;
	}
	}
	void deleteatanypoint(int position){
		node*temp=head;
	if(position=1){
		head=head->next;
		if(head!=NULL){
			head->prev=NULL;
		}
		delete temp;
	}	
		for(int i = 1;i<position-1&&temp!=NULL;i++){
		temp=temp->next;}
		if(temp->prev!=NULL){
			temp->prev->next=temp->next;
		}
		if(temp->next!=NULL){
		temp->next->prev=temp->prev;
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
	insertatanypoint(60,2);
	insertatanypoint(80,4);
	display();	
}
