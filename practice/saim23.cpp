#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
int main(){
	int n;
	int value;
	node*head=NULL;
	node*last=NULL;
	cout<<"enter numbers of node";
	cin>>n;
	for(int i = 0;i<n;i++){
		node*newnode=new node;
		cout<<"enter values";
		cin>>value;
		newnode->data=value;
		newnode->next=NULL;
		if(head==NULL){
			head=newnode;
			last=newnode;
		}
		else{
			last->next=newnode;
			last=newnode;
		}
	}
	cout<<"linked list:";
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<" ";
		temp = temp->next;
	}
}
