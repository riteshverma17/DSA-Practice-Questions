#include <iostream>

using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int& size, int index, int value, int capacity) {
    if (size >= capacity) {
        cout << "Array is full. Cannot insert element." << endl;
        return;
    }
    if (index < 0 || index > size) {
        cout << "Invalid index." << endl;
        return;
    }
    for (int i = size; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    ++size;
    cout << "After insertion: ";
    displayArray(arr, size);
}

void deleteElement(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index." << endl;
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
    cout << "After deletion: ";
    displayArray(arr, size);
}

void updateElement(int arr[], int size, int index, int value) {
    if (index < 0 || index >= size) {
        cout << "Invalid index." << endl;
        return;
    }
    arr[index] = value;
    cout << "After update: ";
    displayArray(arr, size);
}

int main() {
    const int capacity = 10;
    int arr[capacity];
    int size = 0;

    cout << "Enter the initial size of the array (max 10): ";
    cin >> size;
    if (size > capacity || size < 0) {
        cout << "Invalid size." << endl;
        return 1;
    }

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int choice;
    do {
        cout << "\nMenu:\n1. Insert Element\n2. Delete Element\n3. Update Element\n4. Display Array\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int index, value;
                cout << "Enter index to insert at and value: ";
                cin >> index >> value;
                insertElement(arr, size, index, value, capacity);
                break;
            }
            case 2: {
                int index;
                cout << "Enter index to delete: ";
                cin >> index;
                deleteElement(arr, size, index);
                break;
            }
            case 3: {
                int index, value;
                cout << "Enter index to update and new value: ";
                cin >> index >> value;
                updateElement(arr, size, index, value);
                break;
            }
            case 4:
                cout << "Array contents: ";
                displayArray(arr, size);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}
