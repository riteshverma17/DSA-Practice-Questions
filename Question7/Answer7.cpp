#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(int n, vector<int>& prices) {
    if (n == 0) {
        return 0;
    }

    int max_val = 0;
    for (int i = 1; i <= n; ++i) {
        max_val = max(max_val, prices[i - 1] + maxProfit(n - i, prices));
    }

    return max_val;
}

int main() {
    int N = 8;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};

    int result = maxProfit(N, prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}
