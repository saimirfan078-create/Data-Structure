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
void deleteatbeg(){
	node*temp=head;
	if(head==NULL){
		cout<<"invalid";
	}
	if(head!=NULL){
	head=temp->next;
	head->prev=NULL;
	delete temp;
}

}
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp=temp->next;
	}
}
int main(){
	insertatbeg(4);
	insertatbeg(8);
	insertatbeg(6);
	deleteatbeg();
	display();
}
