#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*next;
};
	Node*head=NULL;
	void insertatbeg(int value){
		Node*newnode = new Node;
		newnode->data = value;
		newnode->next = head;
		head = newnode;
	}
	void deleteatbeg(){
		Node*temp=head;
		head=temp->next;
		delete temp;
	}
	void display(){
		Node*temp=head;
		while(temp!=NULL){
			cout<<temp->data;
			temp=temp->next;
		}
		cout<<"NULL";
		}
	int main(){
		insertatbeg(10);
		insertatbeg(20);
		insertatbeg(30);
		deleteatbeg();
		display();
		return 0;
	}

