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
void insertatanypoint(int value,int pos){
	node*newnode=new node;
	newnode->data=value;
	if(pos<1){
		cout<<"invalid";
	}
	if(pos==1){
		insertatbeg(value);
	}
	node*temp=head;
	for(int i =0;i<pos-1&&temp!=NULL;i++){
		temp=temp->next;
	}
	newnode->next=temp->next;
	newnode->prev=temp;
	if(temp->next!=NULL){
		temp->next->prev=newnode;
	}
	temp->next=newnode;
	
}
void deleteatanypoint(int pos){
		node*temp=head;
		if(pos ==1){
			head=temp->next;
			if(head!=NULL){
				head->prev=NULL;
			}
			delete temp;
		}
	for(int i =0;i<pos&&temp!=NULL;i++){
		temp=temp->next;
	}
       temp->prev->next=temp->next;
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
