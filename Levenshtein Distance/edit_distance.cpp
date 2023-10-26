#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minEditDistance(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D array to store the minimum edit distances
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the first row and column
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i; // Number of operations to convert str1[0...i-1] to an empty string
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j; // Number of operations to convert an empty string to str2[0...j-1]
    }

    // Fill in the rest of the matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                // Characters match, no operation needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Characters don't match, find the minimum of insert, delete, and substitute operations
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    // The bottom-right cell contains the minimum edit distance
    return dp[m][n];
}

int main() {
    string str1, str2;

    // Input two strings
    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    // Calculate and output the minimum edit distance
    int distance = minEditDistance(str1, str2);
    cout << "Minimum Edit Distance: " << distance << endl;

    return 0;
}
