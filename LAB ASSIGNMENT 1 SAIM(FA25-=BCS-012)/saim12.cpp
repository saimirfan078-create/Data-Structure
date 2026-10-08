#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* next;
    Node* prev;

    Node(string value) {
        song = value;
        next = NULL;
        prev = NULL;
    }
};

class Playlist {
public:
    Node* first;
    Node* last;

    Playlist() {
        first = NULL;
        last = NULL;
    }

    void addSong(string song) {
        Node* newNode = new Node(song);

        if (first == NULL) {
            first = last = newNode;
            return;
        }

        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }

    void displayForward() {
        Node* temp = first;

        cout << "Playlist Forward: ";

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayBackward() {
        Node* temp = last;

        cout << "Playlist Backward: ";

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

int main() {
    Playlist playlist;

    int n;
    string song;

    cout << "Enter number of songs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter song name: ";
        cin >> song;

        playlist.addSong(song);
    }

    playlist.displayForward();
    playlist.displayBackward();

    return 0;
}
