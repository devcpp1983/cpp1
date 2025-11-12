#include <iostream>
#include <string>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

class PinnacleClub {
private:
    Node* head;

public:
    PinnacleClub() {
        head = NULL;
    }

    void addPresident(int prn, string name) {
        Node* newnode = new Node;
        newnode->prn = prn;
        newnode->name = name;
        newnode->next = head;
        head = newnode;
        cout << "President added\n";
    }

    void addSecretary(int prn, string name) {
        Node* newnode = new Node;
        newnode->prn = prn;
        newnode->name = name;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
        cout << "Secretary added\n";
    }

    // ? FIXED FUNCTION
    void addmember(int prn, string name) {
        if (head == NULL) {
            cout << "Add president first!\n";
            return;
        }

        Node* newnode = new Node;
        newnode->prn = prn;
        newnode->name = name;

        newnode->next = head->next;
        head->next = newnode;

        cout << "Member added\n";
    }

    void deletePresident() {
        if (head == NULL) {
            cout << "Club empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "President deleted\n";
    }

    void deleteSecretary() {
        if (head == NULL) {
            cout << "Club empty\n";
            return;
        }

        if (head->next == NULL) {  // only one node
            delete head;
            head = NULL;
            cout << "Secretary deleted\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;   // ? FIXED ;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        delete temp;
        cout << "Secretary deleted\n";
    }

    void deletemember(int prn) {
        if (head == NULL) {
            cout << "Club empty\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        if (temp->prn == prn) {
            cout << "Use deletePresident()\n";
            return;
        }

        // ? FIXED CONDITION
        while (temp != NULL && temp->prn != prn) {
            prev = temp;        // ? FIXED '='
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Member not found\n";
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Member deleted\n";
    }

    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void display() {
        if (head == NULL) {
            cout << "Club empty\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << "PRN: " << temp->prn 
                 << "  NAME: " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PinnacleClub club;
    int choice, prn;
    string name;

    do {
        cout << "\nMENU\n"
             << "1. Add President\n"
             << "2. Add Secretary\n"
             << "3. Add Member\n"
             << "4. Delete President\n"
             << "5. Delete Secretary\n"
             << "6. Delete Member\n"
             << "7. Count\n"
             << "8. Display\n"
             << "9. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "PRN: ";
            cin >> prn;
            cout << "Name: ";
            cin >> name;
            club.addPresident(prn, name);
            break;

        case 2:
            cout << "PRN: ";
            cin >> prn;
            cout << "Name: ";
            cin >> name;
            club.addSecretary(prn, name);
            break;

        case 3:
            cout << "PRN: ";
            cin >> prn;
            cout << "Name: ";
            cin >> name;
            club.addmember(prn, name);
            break;

        case 4:
            club.deletePresident();
            break;

        case 5:
            club.deleteSecretary();
            break;

        case 6:
            cout << "Enter PRN: ";
            cin >> prn;
            club.deletemember(prn);
            break;

        case 7:
            cout << "Total: " << club.count() << endl;
            break;

        case 8:
            club.display();
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 9);

    return 0;
}
