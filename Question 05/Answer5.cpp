#include <iostream>
using namespace std;


int sumOfDigits(int num) {
    if (num == 0) {
        return 0; 
    }
    return (num % 10) + sumOfDigits(num / 10); 
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Please enter a positive integer!" << endl;
    } else {
        int result = sumOfDigits(number);
        cout << "The sum of the digits of " << number << " is " << result << "." << endl;
    }

    return 0;
}
