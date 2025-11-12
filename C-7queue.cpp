#include <iostream>
using namespace std;

const int MAX = 10;
const int max_name = 100;

string queue[MAX];
int front = 0;
int rear = -1;

void addjob() {
	if ( rear == MAX - 1) {
		cout << "queue is full !\n";
		return;
	}
	else {
		string job;
		cout << "enter job :";
		cin >> job;
		rear++;
		queue[rear] = job;
		cout << "job added successfully !";
	}	
}

void deletejob() {
	if ( front > rear ) {
		cout << "queue is full !";
		return;
	}
	else {
		cout << "job deleted ! " << queue[front] << endl;
		front++;
	}
}

void displayjob() {
	if ( front > rear ) {
		cout << "queue is empty\n";
		return;
	}
	else {
		for( int i = front; i <= rear; i++) {
			cout << "- " << queue[i] << endl;
		}
	}
}

int main() {
	int choice;
	do {
		cout << "\n---MENU---\n";
		cout << "1.add job\n";
		cout << "2.delete job\n";
		cout << "3.display job\n";
		cout << "4.exit\n";
		cout << "enter choice :";
		cin >> choice;
		switch (choice) {
			case 1:
				addjob();
				break;
			case 2:
				deletejob();
				break;
			case 3:
				displayjob();
				break;
			case 4:
				cout << "exiting...";
				break;
			default:
				cout << "invalid !";
		}
	}
	while(choice != 4);
	return 0;
}








