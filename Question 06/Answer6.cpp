#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int num) {
    return (num == 0) ? 0 : 1 + countDigits(num / 10);
}

bool isPalindromeHelper(int num, int leftMultiplier) {
    if (num == 0 || num / 10 == 0) {
        return true;
    }

    int rightDigit = num % 10;
    int leftDigit = num / leftMultiplier;

    if (leftDigit != rightDigit) {
        return false;
    }

    num = (num % leftMultiplier) / 10;
    leftMultiplier /= 100;

    return isPalindromeHelper(num, leftMultiplier);
}

bool isPalindrome(int num) {
    if (num < 0) {
        return false;
    }

    int leftMultiplier = pow(10, countDigits(num) - 1);
    return isPalindromeHelper(num, leftMultiplier);
}

int main() {
    int number;
    cout << "Enter a natural number: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
