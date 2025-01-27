#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int sumUsingLoop(const vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    return sum;
}

int sumUsingRecursion(const vector<int>& nums, int index = 0) {
    if (index == nums.size()) {
        return 0;
    }
    return nums[index] + sumUsingRecursion(nums, index + 1);
}

int sumUsingBuiltin(const vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0);
}

int main() {
    vector<int> nums;
    int n, temp;

    cout << "Enter the number of integers: ";
    cin >> n;

    cout << "Enter the integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "Sum using loop: " << sumUsingLoop(nums) << endl;
    cout << "Sum using recursion: " << sumUsingRecursion(nums) << endl;
    cout << "Sum using built-in function: " << sumUsingBuiltin(nums) << endl;

    return 0;
}
