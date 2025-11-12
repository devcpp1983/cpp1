#include <iostream>
#include <cstdlib>
using namespace std;

struct Seat {
	int seat_no;
	int status;
	Seat *prev;
	Seat *next;
	
	Seat(int s) {
		seat_no = s;
		status = 0;
		prev = next = NULL;
	}
};

Seat *rowhead[10];

void initializeTheater() {
	for (int i = 0; i<10; i++) {
		Seat *head = NULL;
		Seat *tail = NULL;
		
		for (int j = 1; j <= 7; j++) {
			Seat *newseat = new Seat(j);
			
			if( rand() % 3 == 0)
				newseat->status = 1;
				
				
			if (head == NULL) {
				head = tail = newseat;
			}
			else {
				tail->next = newseat;
				newseat->prev = tail;
				tail = newseat;
			}	
		}
		rowhead[i] = head;
	}
}

void displayFreeSeats() {
	cout  << "\nFREE SLOTS\n";
	for( int i=0; i<10; i++) {
		Seat *temp = rowhead[i];
		cout << "ROW " << i + 1 << ": ";
		bool found = false;
		
		while(temp) {
			if( temp->status == 0) {
				cout << temp->seat_no << " ";
				found = true;
			}
			temp = temp->next;
		}
		
		if (!found) {
			cout << "no free slots !";	
		}
	
	cout << endl;
	}
}

void bookSeat(int row, int seat) {
	if ( row < 1 || row > 10 || seat < 1 || seat > 7 ) {
		cout << "invalid seat number !";
		return;
	}
	
	Seat *temp = rowhead[row -1];
	while ( temp && temp->seat_no != seat) {
		temp = temp->next;
	}
	
	if(!temp) {
		cout << "seat not found !";
	}
	else if( temp->status == 1) {
		cout << "seat is booked !";
	}
	else {
		temp->status = 1;
		cout << "seat booked successfully !";
	}
}

int main() {
	initializeTheater();
	int choice;
	
	do {
		cout << "MENU\n";
		cout << " 1.display free slots\n 2.book seat\n 3.exit\n enter your choice : ";
		cin >> choice;
		
		switch(choice) {
			case 1:
				displayFreeSeats();
				break;
			case 2:
				int row, seat;
				cout << "select row (1-10) :";
				cin >> row;
				cout << "select seat (1-7) :";
				cin >> seat;
				bookSeat(row, seat);
				break;
			case 3:
				cout << "exiting...";
				break;
			default:
				cout << "invalid choice !";
		}
	}
	while(choice != 3);
	return 0;
}
