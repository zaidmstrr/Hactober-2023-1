#include <bits/stdc++.h>
using namespace std;

int countPaths(int m, int n, vector<vector<int>>& dp) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Base condition: If we are at the top-left cell (0, 0), there is only one way.
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; 
            }

            // Initialize variables to store the number of ways from the cell above (up) and left (left).
            int up = 0;
            int left = 0;

            //i>0 ans j>0 needs to be checked so that we find answer only by staying inside the boundary of grid
            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            dp[i][j] = up + left;
        }
    }
return dp[m - 1][n - 1];
}


int countWays(int m, int n) {
  
    // Create a 2d-vector (dp) to store the results of subproblems.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return countPaths(m, n, dp);
}

int main() {
    int m,n;
    cin>>m>>n;
    
    cout << "Number of ways to reach from (0,0) to (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}
