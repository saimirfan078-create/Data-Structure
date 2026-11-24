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
void insertatanypoint(int value,int pos){
	if(pos<1){
		cout<<"invalid place";
	}
	if(pos==1){
		insertatbeg(value);
	}
	node*newnode=new node;
	newnode->data=value;
	node*temp=head;
	for(int i=0;i<pos-1&&temp!=NULL;i++){
		temp=temp->next;
	}
	if(temp==NULL){
		cout<<"invalid";
	}
	newnode->next=temp->next;
	temp->next=newnode;
	
}
void deleteatanypoit(int pos){
	if(pos==1){
		node*temp=head;
		head=temp->next;
		delete temp;
	}
	node*temp=head;
	for(int i=0;i<pos-1&&temp!=NULL;i++){
		temp = temp->next;
	}
	node*delt=temp->next;
	temp->next=delt->next;
	delete delt;
}

void display(){
	node*temp=head;
	while(temp!=NULL){
	cout<<temp->data;
	temp=temp->next;
}
}
int main(){
	insertatbeg(10);
		insertatbeg(20);
		insertatbeg(30);
		insertatanypoint(50,2);
		deleteatanypoit(3);
		display();
		return 0;
}
