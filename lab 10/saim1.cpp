
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    int patientID;
    string name;
    int age;
    string disease;
    int priority;
};

// Comparator for priority queue
struct Compare {
    bool operator()(Patient a, Patient b) {
        return a.priority > b.priority;
    }
};

int main() {

    priority_queue<Patient, vector<Patient>, Compare> hospital;

    int choice;

    do {
        cout << "\n===== HOSPITAL REGISTRATION SYSTEM =====";
        cout << "\n1. Register Patient";
        cout << "\n2. Treat Next Patient";
        cout << "\n3. Display Next Patient";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;

            cout << "\nEnter Patient ID: ";
            cin >> p.patientID;

            cin.ignore();

            cout << "Enter Patient Name: ";
            getline(cin, p.name);

            cout << "Enter Patient Age: ";
            cin >> p.age;

            cin.ignore();

            cout << "Enter Disease/Condition: ";
            getline(cin, p.disease);

            cout << "\nPriority Levels:";
            cout << "\n1. Critical/Emergency";
            cout << "\n2. Serious";
            cout << "\n3. Moderate";
            cout << "\n4. Normal";

            cout << "\nEnter Priority: ";
            cin >> p.priority;

            if (p.priority >= 1 && p.priority <= 4) {
                hospital.push(p);
                cout << "\nPatient Registered Successfully!";
            }
            else {
                cout << "\nInvalid Priority Level!";
            }
        }

        else if (choice == 2) {

            if (hospital.empty()) {
                cout << "\nNo Patients Waiting!";
            }
            else {
                Patient p = hospital.top();
                hospital.pop();

                cout << "\nPatient Being Treated:";
                cout << "\nPatient ID: " << p.patientID;
                cout << "\nName: " << p.name;
                cout << "\nAge: " << p.age;
                cout << "\nCondition: " << p.disease;
                cout << "\nPriority: " << p.priority;
            }
        }

        else if (choice == 3) {

            if (hospital.empty()) {
                cout << "\nNo Patients Waiting!";
            }
            else {
                Patient p = hospital.top();

                cout << "\nNext Patient:";
                cout << "\nPatient ID: " << p.patientID;
                cout << "\nName: " << p.name;
                cout << "\nCondition: " << p.disease;
                cout << "\nPriority: " << p.priority;
            }
        }

        else if (choice == 4) {
            cout << "\nExiting Hospital System...";
        }

        else {
            cout << "\nInvalid Choice!";
        }

    } while (choice != 4);

    return 0;
}

