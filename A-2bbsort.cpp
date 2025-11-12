#include <iostream>
#include <algorithm>
using namespace std;

void selectionsort( float arr[], int n) {
	for( int i = 0; i < n-1; i++) {
		int minindex = i;
		for( int j = i+1; j < n; j++) {
			if( arr[j] < arr[minindex])
				minindex = j;
		}
		swap( arr[i], arr[minindex]);
	}
}

void display ( float arr[], int n) {
	cout << "TOP FIVE \n";
	for( int i = n-1; i >= max(n-5,0); i--) {
	cout << arr[i] << endl;
	}
}

int main() {
	int n;
	
	cout << "enter no of students :\n";
	cin >> n;
	
	float arr[n];
	
	cout << "enter percentages :\n";
	for( int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	selectionsort( arr, n);
	display( arr, n);
	
	return 0;
	
}
