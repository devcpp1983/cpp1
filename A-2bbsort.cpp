#include <iostream>
#include <algorithm>
using namespace std;

void bubblesort( float arr[], int n) {
	for( int i = 0; i < n-1; i++) {
		for( int j = 0; j < n-i-1; j++) {
			if ( arr[j] > arr[j+1]) 
				swap( arr[j], arr[j+1]);
		}
	}
}

void display ( float arr[], int n) {
	cout << "TOP FIVE \n";
	for(int i = n-1; i >= max(n-5,0); i--) {
		cout << arr[i] << endl;
	} 
}

int main() {
	int n;
	cout << "enter the number of students :";
	cin >> n;
	
	float arr[n];
	
	cout << "enter percentages :\n";
	for( int i=0; i <n; i++) {
		cin >> arr[i];
	}	
	
	bubblesort( arr, n);
	display( arr,n);
	
	
	
	return 0;
}
