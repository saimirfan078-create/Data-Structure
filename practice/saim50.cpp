#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
node*head=NULL;
void insertatbeg(int value){
	node*newnode=new node;
	newnode->data=value;
	
	newnode->next=head;
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
	newnode->next=temp->next;
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
	temp->next=newnode;
}
void deleteatbeg(){
	node*temp=head;
	head=temp->next;
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
