#include <iostream>
#include <algorithm>

using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        swap(arr[i], arr[size - 1 - i]);
    }
    cout << "Reversed array: ";
    displayArray(arr, size);
}

bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void findMaxMin(int arr[], int size, int& max, int& min) {
    max = arr[0];
    min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
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
        cout << "\nMenu:\n1. Reverse Array\n2. Check if Array is Sorted\n3. Find Maximum and Minimum\n4. Display Array\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                reverseArray(arr, size);
                break;
            case 2:
                if (isSorted(arr, size)) {
                    cout << "The array is sorted in ascending order." << endl;
                } else {
                    cout << "The array is not sorted." << endl;
                }
                break;
            case 3: {
                int max, min;
                findMaxMin(arr, size, max, min);
                cout << "Maximum element: " << max << ", Minimum element: " << min << endl;
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
