#include <iostream>
using namespace std;

int LinearSearch(int roll[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (roll[i] == key) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int roll[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (roll[mid] == key)
            return mid;
        else if (roll[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, choice, key, result;

    cout << "Enter number of students: ";
    cin >> n;

    int roll[n];
    cout << "Enter roll numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> roll[i];
    }

    do {
        cout << "\n---- Menu ----\n";
        cout << "1. Search using Linear Search\n";
        cout << "2. Search using Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter roll number to search: ";
                cin >> key;
                result = LinearSearch(roll, n, key);

                if (result != -1)
                    cout << "Roll number " << key << " attended the program\n";
                else
                    cout << "Roll number " << key << " not found\n";
                break;

            case 2:
                cout << "Enter roll number to search: ";
                cin >> key;
                result = BinarySearch(roll, n, key);

                if (result != -1)
                    cout << "Roll number " << key << " attended the program\n";
                else
                    cout << "Roll number " << key << " not found\n";
                break;

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
