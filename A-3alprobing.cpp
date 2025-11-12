#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Client {
	string name;
	string phone;
	bool occupied;
	
	Client() {
		name = "";
		phone = "";
		occupied = false;
	}
};

int hashfunction( string key) {
	int sum = 0;
	for( int i = 0; i < key.length(); i++)
		sum += key[i];
	
	return sum % TABLE_SIZE;

}

void insert( Client table[], string name, string phone) {
	int index = hashfunction( name );
	
	for ( int i = 0; i < TABLE_SIZE; i++) {
		int newindex = (index + i) % TABLE_SIZE;
		
		if( !table[newindex].occupied){
			table[newindex].name = name;
			table[newindex].phone = phone;
			table[newindex].occupied = true;
			cout << "inserted at :" << newindex << endl;
			return;
			}
	}
	cout << "table is full !";
}

string search( Client table[], string name) {
	int index = hashfunction(name);
	
	for( int i =0; i < TABLE_SIZE; i++) {
		int newindex = ( index + i) % TABLE_SIZE;
		
		if( !table[newindex].occupied)
			return "not found !";
		
		if( table[newindex].name == name) 
			return table[newindex].phone;
		
	}
	cout << "not found !";
}

void display( Client table[]) {
	cout << "\n HASH TABLE \n";
	
	for( int i = 0; i < TABLE_SIZE; i++) {
		cout << i << ": ";
		
		if( table[i].occupied) {
			cout << table[i].name << "-> " << table[i].phone;
		}
		else
			cout << "empty";
	cout << endl;			
	}
		
}


int main() {
	
	Client table[TABLE_SIZE];
	int choice;
	string name, phone;
	
	do {
		
		cout << "\nMENU\n";
		cout << "1.insert\n";
		cout << "2.search\n";
		cout << "3.display\n";
		cout << "4.exit\n";
		cout << "enter your choice : ";
		cin >> choice;
		
		switch (choice) {
			case 1:
				cout << "enter name : ";
				cin >> name;
				cout << "enter phone : ";
				cin >> phone;
				
				insert(table, name, phone);
				break;
				
			case 2:
				cout << "enter name :";
				cin >> name;
				cout << "result : " << search( table, name);
				break;
				
			case 3:
				display( table);
				break;
				
			case 4:
				cout << "exiting...";
				break;
				
			default:
				cout << "invalid choice :";
		}
		
		
	}
	while( choice != 4);
	return 0;
}
