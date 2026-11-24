#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
node*head=NULL;
void insertatbeg(int value){
	node*newnode = new node;
	newnode->data=value;
	newnode->next=head;
	head = newnode;
}
void insertatanypoint(int value,int position){
if(position<1){
	cout<<"invalid position";
}
if(position==1){
	insertatbeg(value);
	return;
}
node*newnode = new node;
newnode->data=value;
node*temp=head;
for(int i = 1;i<position-1&&temp!=NULL;i++){
	temp = temp->next;
}
newnode->next=temp->next;
temp->next=newnode;
}
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<' ';
		temp = temp->next;
	}
}
void deleteatanypoint(int position){
	if(position=1){
		node*temp=head;
		head=temp->next;
		delete temp;
	}
	node*temp=head;
	for(int i = 1;i<position-1&&temp!=NULL;i++){
	temp = temp->next;
	node*delnode=temp->next;
	temp->next=delnode->next;
	delete delnode;
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
