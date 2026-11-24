#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
struct dnode{
	int data;
	dnode*next;
	dnode*prev;
};
dnode*converttoddl(node*head){
	dnode*newhead=NULL;
	dnode*last=NULL;
	node*temp=head;
	while(temp!=NULL){
		dnode*newnode=new dnode;
		newnode->data=temp->data;
		newnode->next=NULL;
		newnode->prev=last;
		if(newhead==NULL){
			newhead=newnode;
		}
		else{
			last->next=newnode;
		}
		temp=temp->next;
		
	}
}
void display(dnode* head)
{
    dnode* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
	node*head=new node{10,NULL};
	head->next=new node{20,NULL};
	head->next=new node{30,NULL};
	 dnode* dll = converttoddl(head);

    cout << "Doubly Linked List: ";
    display(dll);

    return 0;
}
