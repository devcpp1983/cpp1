#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}


int height(Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}


int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}


void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, value;

 
    cout << "How many values do you want to insert into the BST? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInitial BST (Inorder Traversal): ";
    inorder(root);
    cout << "\n";

   
    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert New Node\n";
        cout << "2. Find Longest Path (Height)\n";
        cout << "3. Find Minimum Value\n";
        cout << "4. Display Inorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Inserted successfully!\n";
                break;

            case 2:
                cout << "Height (Longest Path): " << height(root) << endl;
                break;

            case 3:
                value = findMin(root);
                if (value != -1)
                    cout << "Minimum value in BST: " << value << endl;
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
