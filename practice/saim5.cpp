#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
int main(){
	node*head=NULL;
	node*temp = new node;
	temp->data=10;
	temp->next=NULL;
	head=temp;
	cout<<temp->data;
	
}
