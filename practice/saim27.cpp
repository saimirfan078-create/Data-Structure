#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
void insertatend(node*&head,int value){
	node*newnode = new node;
	newnode->data=value;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		return;
	}
		node*temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	
}
 node*merge(node*head1,node*head2){
 	node*head3=NULL;
 	node*temp=head1;
 	while(temp!=NULL){
	insertatend(head3,temp->data);
		temp=temp->next;
	}
	head2=temp;
	while(temp!=NULL){
		insertatend(head3,temp->data);
			temp=temp->next;
		
	}
	return head3;
 }
 	void display(node* head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
	node*head1=NULL;
	node*head2=NULL;
	node*head3=NULL;
	 insertatend(head1, 10);
    insertatend(head1, 20);
    insertatend(head1, 30);

    // Second linked list
    insertatend(head2, 40);
    insertatend(head2, 50);
    insertatend(head2, 60);

    cout << "First List: ";
    display(head1);

    cout << "Second List: ";
    display(head2);

    // Merge both lists
    head3 = merge(head1, head2);

    cout << "Merged List: ";
    display(head3);

    return 0;

}
