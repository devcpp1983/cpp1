#include <iostream>
using namespace std;

LinearSearch( int roll[], int n, int key) {
	for( int i=0; i<n; i++) {
		if( roll[i] = key) {
			return i;
		}
	}
	return -1;
}

BinarySearch( int roll[], int n, int key) {
	int low=0, high= n-1;
	while( low <= high) {
		int mid = (low + high) / 2;
		
		if (roll[mid] == key) 
			return mid;
		else if ( roll[mid] <= key) 
			low = mid+1;
		else 
		    high = mid-1;
	}
	return -1;
}

int main() {
	int n, choice, key, result;
	cout << "Enter number of the student: ";
	cin >> n;
	
	int roll[n];
	cout << "Enter roll numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> roll[i];
	}
	
	do {
		cout <<"\n----Menu----\n";
		cout <<"1. search using linear search\n";
		cout <<"2. search using binary search\n";
		cout <<"3. exit\n";
		cout <<"enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			case 1:
				cout << "enter roll number to search: ";
				cin >> key;
				result = LinearSearch(roll,n,key);
				if (result != -1) 
					cout << "Roll number " << key << " attended the program\n";
				else
					cout << "Roll number " << key <<" not found\n";
				break;
			
			case 2:
				cout <<"enter roll number to search :";
				cin >> key;
				result = BinarySearch(roll,n,key);
				if (result != -1) 
					cout << "Roll number " << key << " attended the program\n";
				else
					cout << "Roll number " << key <<" not found\n";
				break;
				
			case 3:
				cout << "Exiting program\n";
				break;
		    
		    defaul:
		    	cout << "invalid choice!";	
		}
		
	}while (choice != 3);
	return 0;
}
