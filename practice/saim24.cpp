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
void deleteatbeg(){
	node*temp=head;
	head=temp->next;
	
	delete temp;
}
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
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
