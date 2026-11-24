#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*head=NULL;
void insertatbeg(int value){
	Node*newnode = new Node;
	newnode->data=value;
	newnode->next=head;
	head = newnode;
}
void insertatanypoint(int value,int position){
	if(position<1){
		cout<<"Invalid Position";
	}
	if(position==1){
		insertatbeg(value);
	}
	Node*newnode = new Node;
	newnode->data=value;
	Node*temp = head;
	for(int i = 1;i<position-1&&temp!=NULL;i++){
		temp = temp->next;
	}
	if(temp==NULL){
		cout<<"Invalid position";
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void deleteatanypoint(int position){
	if(position == 1){
	Node*temp=head;
	head=temp->next;
	delete temp;
	}
	Node*temp=head;
	for(int i = 0;i<position-1&&temp!=NULL;i++){
		temp=temp->next;
}
	Node*delnode=temp->next;
	temp->next=delnode->next;
	delete delnode;
}
void display(){
	Node*temp=head;
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
		deleteatanypoint(3);
		display();
		return 0;
}
