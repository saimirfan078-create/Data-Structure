#include<iostream>
using namespace std;
struct node{
	char data;
	node*next;
};
class stacklinked{
	private:
		node*head;
		public:
		stacklinked(){
			head=NULL;
		}	
		void push(char s){
			node*newnode=new node;
			newnode->data=s;
			newnode->next=head;
			head=newnode;
		}
		char pop(){
			if(head==NULL){
				cout<<"list not exist";
				return ' ';	
			}
			else{
				node*temp=head;
				char T = temp->data;
				head=temp->next;
				delete temp;
				return T;
			}
		}
		void display(){
			if(head==NULL){
				cout<<"node is not exist";
				
			}
			node*temp=head;
			while(temp!=NULL){
				cout<<temp->data;
				temp=temp->next;
			}
		}
};
int main()
{
    stacklinked sl;

    sl.push('w');
    sl.push('e');
    sl.push('t');
    sl.push('y');

    cout<<"Before Pop: ";
    sl.display();

    cout<<"\nAfter Pop: ";

    sl.pop();
    sl.pop();
    sl.pop();
    sl.pop();

    sl.display();

    return 0;
}
