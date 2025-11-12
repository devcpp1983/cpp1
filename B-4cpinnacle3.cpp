#include <iostream>
#include <string>
using namespace std;

struct Node {
	int prn;
	string name;
	Node *next;
};

class PinnacleClub{
	
private:
	Node* head;

public:
	 PinnacleClub() {
	 	head = NULL;
	 }
	 
	 void addPresident( int prn, string name) {
	 	Node *newnode = new Node;
	 	newnode->prn = prn;
	 	newnode->name = name;
	 	newnode->next = head;
	 	head = newnode;
	 	cout << "president added\n";
	 }
	 
	 void addSecretary(int prn, string name) {
	 	Node *newnode = new Node;
	 	newnode->prn = prn;
	 	newnode->name = name;
	 	newnode->next = NULL;
	 	
	 	if(head == NULL) {
	 		head = newnode;
		 }
		 else {
		 	Node *temp = head;
		 	while ( temp->next != NULL) 
		 		temp = temp->next;
		 		
		 	temp->next = newnode;
			 
		 }
		 cout << "secretary added\n";
	 }
	 
	 void addMember(int prn, string name) {
	 	if (head == NULL) {
	 		cout << "enter president first\n";
	 		return;
		}
		
		Node *newnode = new Node;
		newnode->prn = prn;
		newnode->name = name;
		
		newnode->next = head->next;
		head->next = newnode;
		
		cout << "member added\n";
	 }
	 
	 int count() {
	 	int count = 0;
	 	Node *temp = head;
	 	while (temp != NULL) {
	 		count++;
	 		temp = temp->next;
		 }
		 return count;
	 }
	 
	 void display() {
	 	if( head == NULL) {
	 		cout << "club empty\n";
	 		return;
		 }
		 
		 Node *temp = head;
		 while( temp != NULL) {
		 	cout << "PRN :" << temp->prn << "NAME :" << temp->name << endl;
		 	temp = temp->next;
		 }
	 }
	 
	 void concatenate( PinnacleClub & B) {
	 	if(head == NULL) {
	 		head = B.head;
	 		return;
		 }
		 
		Node *temp = head;
		while( temp->next != NULL) 
		 	temp = temp->next;
		
		temp->next = B.head; 	
	}
};

int main() {
	PinnacleClub DivA, DivB, FinalList;
	string name;
	int prn, choice;
	
	do {
		cout <<"\n---MENU---\n";
		cout << " 1.add pre(A)\n 2.add sec(A)\n 3.add mem(A)\n 4.display Div A\n";
		cout << " 5.add pre(B)\n 6.add sec(B)\n 7.add mem(B)\n 8.display Div B\n";
		cout << " 9.concatenate (A & B)\n 10.Display (A & B)\n 11.count (A & B)\n";
		cout << " 12.exit\n enter choice :";
		cin >> choice;
		
		switch(choice) {
			case 1:
				cout << "PRN :";
				cin >> prn;
				cout << "NAME :";
				cin >> name;
				DivA.addPresident(prn, name);
				break;
			case 2:
				cout << "PRN :";
				cin >> prn;
				cout << "NAME :";
				cin >> name;
				DivA.addSecretary(prn, name);
				break;
			case 3:
				cout << "PRN :";
				cin >> prn;
				cout << "NAME :";
				cin >> name;
				DivA.addMember(prn, name);
				break;
			case 4:
				DivA.display();
				break;
			case 5:
				cout << "PRN :";
				cin >> prn;
				cout << "NAME :";
				cin >> name;
				DivB.addPresident(prn, name);
				break;
			case 6:
				cout << "PRN :";
				cin >> prn;
				cout << "NAME :";
				cin >> name;
				DivB.addSecretary(prn, name);
				break;
			case 7:
				cout << "PRN :";
				cin >> prn;
				cout << "NAME :";
				cin >> name;
				DivB.addMember(prn, name);
				break;
			case 8:
				DivB.display();
				break;
			case 9:
				FinalList = DivA;
				FinalList.concatenate(DivB);
				cout << "list concaneted";
				break;
			case 10:
				FinalList.display();
				break;
			case 11:
				cout << "total :" << FinalList.count();
				break;
			case 12:
				cout << "exiting...";
				break;
			default:
				cout << "invalid !";
		}
	}
	while( choice != 12);
	return 0;
}






