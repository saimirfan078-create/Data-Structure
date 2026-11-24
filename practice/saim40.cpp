#include<iostream>
using namespace std;
int queue[5];
	int front=-1;
	int rear=-1;
	void enqueue(int value){
	cout<<"enter value";
	cin>>value;
	if(rear==4){
		cout<<"lsit is full";
	}
	else {
    if(front==-1){
		front=0;
	}}
	rear++;
	queue[rear]=value;
}

void dequeue(){
	if(front==-1||front>rear){
		cout<<"queue empaty";
		
	}
	else{
		cout << "Deleted Element: " << queue[front] << endl;
		front++;
	}
}
void display(){
	if(rear==-1){
		cout<<"queue is empty";
	}
	for(int i =front;i<=rear;i++){
		cout<<queue[i];
	}
}
int main(){
	 enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue Elements: ";
    
    display();
    cout << "After Dequeue: ";
    dequeue();
    display();

    return 0;
	
}
