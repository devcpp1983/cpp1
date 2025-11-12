#include <iostream>
#include <string>
using namespace std;

struct Node{
	int prn;
	string name;
	Node *next;
};

class PinnacleClub{
private:
	Node *head;
	
public:
	
	PinnacleClub() {
		head = NULL;
	}
	
	void addPresident(int prn, string name) {
		Node *newnode = new Node;
		newnode->prn = prn;
		newnode->name = name;
		newnode->next = head;
		head = newnode;
		cout << "Presedent added !\n";
	}
	
	void addSecretary( int prn, string name) {
		Node *newnode = new Node;
		newnode->prn = prn;
		newnode->name = name;
		newnode->next = NULL;
		
		if (head == NULL) {
			head = newnode;
		}
		else {
			Node *temp = head;
			while (temp->next != NULL) 
				temp = temp->next;
				
			temp->next = newnode;
			}
		cout << "secretary added !\n";
	}
	
	void addMember(int prn, string name) {
		if ( head == NULL) {
			cout << "add president first !";
			return;
		}
		
		
		Node *newnode = new Node;
		newnode->prn = prn;
		newnode->name = name;
		
		newnode->next = head->next;
		head->next = newnode;
			
		cout << "member added \n";
	}
	
	int count() {
		int count = 0;
		Node *temp = head;
		while(temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}
	
	void display() {
		
		if(head == NULL) {
			cout << "club is empty !\n";
			return;
		}
		
		cout << "Club members are...\n";
		Node *temp = head;
		while( temp != NULL) {
			cout << "PRN :" << temp->prn << "NAME :" << temp->name << endl;
			temp = temp->next;
		}
	}

};

int main() {
	PinnacleClub club;
	int prn, choice;
	string name;
	
	do {
		cout << "MENU\n";
		cout << " 1.add president\n 2.add secretary\n 3.add member\n 4.count\n 5.display\n 6.exit\n";
		cout << "enter your choice :";
		cin >> choice;
	
		switch (choice) {
			case 1:
				cout << "enter prn :";
				cin >>prn;
				cout << "enter name :";
				cin >> name;
				club.addPresident(prn, name);
				break;
			case 2:
				cout << "enter prn :";
				cin >>prn;
				cout << "enter name :";
				cin >> name;
				club.addSecretary(prn, name);
				break;
			case 3:
				cout << "enter prn :";
				cin >>prn;
				cout << "enter name :";
				cin >> name;
				club.addMember(prn, name);
				break;
			case 4:
				cout << "Total " << club.count() << " members ";
				break;
			case 5:
				club.display();
				break;
			case 6:
				cout << "exiting...";
				break;
			default:
				cout << "invalid choice !";
	}	
	
	}
	while ( choice != 6);
	
	
	return 0;
}
