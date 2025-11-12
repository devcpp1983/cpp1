#include <iostream>
#include <string>
using namespace std;

const int M = 10;

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

int hashfunction( string key ) {
	int sum = 0;
	
	for( int i = 0; i < key.length(); i++ ) 
		sum += key[i];
		
	return sum % M;
	
}

void insert ( Client table[], string name, string phone) {
	int index = hashfunction( name);
	
	for( int i = 0; i < M; i++) {
		int newindex = ( index + i * i) % M;
		
		if( !table[newindex].occupied) {
			table[newindex].name = name;
			table[newindex].phone = phone;
			table[newindex].occupied = true;
			
		return;
		}
	}
	cout << "table is full !";
}

string search( Client table[], string name) {
	int index = hashfunction( name);
	
	for(int i = 0; i < M; i++) {
		int newindex = (index + i*i) % M;
		
		if(!table[newindex].occupied)
			return "not found !";
			
		if(table[newindex].name == name)
			return table[newindex].phone;
			
			
	}
	return "not found !";
}

void display( Client table[]) {
	cout << "HASH TABLE \n";
	
	for(int i=0; i<M; i++) {
		cout << i << ": ";
		
		if( table[i].occupied) {
			cout << table[i].name << "-> " << table[i].phone;
		}
		else {
			cout << "empty";
	}
	cout << endl;	
	
	}
}

int main() {
	Client table[M];
	string name, phone;
	int choice;
	
	do{
		cout << "MENU\n 1.insert\n 2.search\n 3.display\n 4.exit\n enter your choice : ";
		cin >> choice;
		
		switch (choice) {
			case 1:
				cout << "enter name :";
				cin >> name;
				cout << "enter phone :";
				cin >> phone;
				insert( table, name, phone);
				break;
				
			case 2:
				cout << "enter name :";
				cin >> name;
				
				search(table, name);
				break;
				
			case 3:
				display(table);
				break;
				
			case 4:
				cout << "exiting...";
				break;
				
			default:
				cout << "invalid choice !";
				
		}
	}
	while( choice != 4);
	return 0;
}
