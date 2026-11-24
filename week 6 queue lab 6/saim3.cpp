#include <iostream>
#include <string>
using namespace std;

template <class T>
class Q {
private:
    T Data[10];
    int front;
    int rear;
    int count;

public:
    Q() { 
        front = 0; 
        rear = 0; 
        count = 0; 
    }

    bool isEmpty() { 
        return (count == 0); 
    }

    bool isFull() { 
        return (count == 10); 
    }

    void enQue(T x);
    T deQue();
};

template <class T>
void Q<T>::enQue(T x) {
    if (!isFull()) {
        Data[rear] = x;
        rear++;
        rear = rear % 10; // Circular wrap-around
        count++;
    } else {
        cout << "\nSorry Q is Full";
    }
}

template <class T>
T Q<T>::deQue() {
    T temp;
    if (!isEmpty()) {
        temp = Data[front];
        front++;
        front = front % 10; // Circular wrap-around
        count--;
    } else {
        cout << "\nSorry Q is Empty";
        temp = T(); // Safe default value for any template type
    }
    return temp;
}

int main() {
    Q<int> q1;
    Q<char> q2;
    Q<string> q3;

    q1.enQue(4);
    q1.enQue(7);
    q1.enQue(9);
    cout << "\nDequeued value from q1: " << q1.deQue();

    q2.enQue('A');
    q2.enQue('B');
    q2.enQue('C');
    cout << "\nDequeued value from q2: " << q2.deQue();

    q3.enQue("I");
    q3.enQue("Love");
    q3.enQue("Programming");
    cout << "\nDequeued value from q3: " << q3.deQue();
    cout << "\nDequeued value from q3: " << q3.deQue();
    cout << "\nDequeued value from q3: " << q3.deQue();

    return 0;
}
