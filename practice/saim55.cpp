#include<iostream>
using namespace std;
class queue{
	public:
		int size;
		int *q;
		int front;
		int rear;
		queue(){
			size=10;
			q=new int[size];
			front=-1;
			rear=-1;
		}
		queue(int x){
			size=x;
			q=new int[size];
			front=-1;
			rear=-1;
		}
		bool_is_empty(){
			return rear==-1;
		}
		bool_is_full(){
			return rear == size-1;
		}
		void enqueue(int value){
			if(bool_is_full()){
				cout<<"space s full";
			}else if(bool_is_empty()){
				rear=front=0;
			}else{
				rear++;
			}
			q[rear]=x;
		}
		int dequeue(){
			
			if(bool_is_empty){
				cout<<"queue is empty";
			}else{
				int x = q[front];
				if(front==rear){
					front=rear=-1;
				}
				else{
					front++
				}
				return x;
			}
			
		}
};
int main()
{
    Que q1(5);

    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);

    cout << "Queue: ";
    q1.display();

    cout << "\nDeleted: " << q1.Dequeue();

    cout << "\nAfter Dequeue: ";
    q1.display();

    return 0;
}
