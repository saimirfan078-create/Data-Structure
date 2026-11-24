
#include <iostream> // Provides input and output operations
using namespace std; // Allows standard library names without std::

// Defines a node of the singly linked list
struct Node {
    int data;      // Stores the node value
    Node* next;    // Points to the next node

    // Initializes a new node
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Inserts a new node at the end of the linked list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        return newNode;
    }

    // Moves to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Links the last node to the new node
    temp->next = newNode;

    return head;
}

// Displays the linked list when it does not contain a cycle
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Finds the middle using slow and fast pointers
Node* findMiddle(Node* head) {
    // Handles an empty linked list
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    int iteration = 0;

    // Slow moves one step while fast moves two steps
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        iteration++;

        // Displays the pointer trace after each iteration
        cout << "Iteration " << iteration;
        cout << ": Slow = " << slow->data;

        if (fast != NULL) {
            cout << ", Fast = " << fast->data;
        } else {
            cout << ", Fast = NULL";
        }

        cout << endl;
    }

    // Slow points to the middle; for even lists, it is the second middle
    return slow;
}

// Detects a cycle using Floyd's fast/slow pointer algorithm
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Fast moves two steps and slow moves one step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If both pointers meet, a cycle exists
        if (slow == fast) {
            return true;
        }
    }

    // Fast reaches NULL if no cycle exists
    return false;
}

// Frees memory after the cycle, if any, has been removed
void deleteList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Demonstrates middle-node and cycle-detection operations
int main() {
    Node* head = NULL;

    // Creates the required seven-node linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    head = insertAtEnd(head, 60);
    head = insertAtEnd(head, 70);

    // Displays the original list
    cout << "Original Linked List:" << endl;
    display(head);

    // Finds and displays the middle node
    cout << "\nFinding Middle Node:" << endl;
    Node* middle = findMiddle(head);

    if (middle != NULL) {
        cout << "Middle Node = " << middle->data << endl;
    }

    // Checks the original list for a cycle
    cout << "\nCycle Detection on Normal List:" << endl;

    if (hasCycle(head)) {
        cout << "Cycle detected." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Finds the last node
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Finds the second node to connect the last node to it
    Node* second = head->next;

    // Creates a cycle by connecting the last node to node 20
    last->next = second;

    // Checks the list after creating a cycle
    cout << "\nCycle Detection After Connecting Last to 20:" << endl;

    if (hasCycle(head)) {
        cout << "Cycle detected." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Removes the cycle before freeing memory
    last->next = NULL;

    // Frees all nodes to avoid a memory leak
    deleteList(head);

    return 0; // Ends the program successfully
}

