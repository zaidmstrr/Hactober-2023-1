#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 5;  // Replace with the number of stairs you want to climb

    int ways = climbStairs(n);

    cout << "Number of distinct ways to climb " << n << " stairs: " << ways << endl;

    return 0;
}
//Hacktoberfest 2023
//Optimal Solution
