#include <iostream>
#include <cstdlib>
using namespace std;

struct Seat {
	int seat_no;
	int status;
	Seat *next;
	Seat *prev;
	
	Seat(int s) {
		seat_no = s;
		status = 0;
		next = prev = NULL;
	}
};

Seat *rowhead[10];

void initializeTheatre() {
	for( int i = 0; i < 10; i++) {
		Seat *head = NULL;
		Seat *tail = NULL;
		
		for( int j = 1; j <= 7; j++) {
			Seat *newseat = new Seat(j);
			
			if( rand() % 3 == 0) {
				newseat->status = 1;
			}
			
			if( head == NULL) {
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

void displayBookedSeats() {
	cout << "\nBOOKED SEATS\n";
	for( int i =0; i <10; i++){
		
		Seat *temp = rowhead[i];
		cout << "ROW " << i + 1 << ": ";
		bool found = false;
		
		while (temp) {
			if( temp->status == 1) {
				cout << temp->seat_no << " ";
				found = true;
			}
			temp = temp->next;
		}
		
		if( !found ) {
			cout << "no booked seats !";
		}
		
		cout << endl;
	}
}

void cancelSeat( int row, int seat) {
	if( row < 1 || row > 10 || seat < 1 || seat > 7) {
		cout << "invalid !" ;
		return;
	}
	
	Seat *temp = rowhead[ row - 1];
	while ( temp && temp->seat_no != seat) {
		temp = temp->next;
	}
	
	if( !temp ) {
		cout << "seat not found! ";
	}
	else if ( temp->seat_no == 0 ) {
		cout << "seat is free !";
	}
	else {
		temp->status = 0;
		cout << "seat canceled successfully !";
	}
}

int main() {
	initializeTheatre();
	int choice;
	
	do {
		cout << "\nMENU\n";
		cout << "1.display booked slots\n";
		cout << "2.cancel seat\n";
		cout << "3.exit\n";
		cout << "enter choice :";
		cin >> choice;
		
		switch (choice) {
			case 1:
				displayBookedSeats();
				break;
			case 2:
				int row, seat;
				cout << "ROW (1 to 10) :";
				cin >> row;
				cout << "SEAT (1 to 7) :";
				cin >> seat;
				cancelSeat(row, seat);
				break;
			case 3:
				cout << "exiting...";
				break;
			default:
				cout << "invalid !";
		}
	}
	while ( choice != 3);
	return 0;
}
